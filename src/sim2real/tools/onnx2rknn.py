#!/usr/bin/env python3
import argparse
import os
import sys


def parse_input_size(text):
    if text is None or text.strip() == "":
        return None
    return [int(x) for x in text.split(",")]


def main():
    parser = argparse.ArgumentParser(description="Convert ONNX model to RKNN model.")
    parser.add_argument("--onnx", required=True, help="Input ONNX model path")
    parser.add_argument("--output", required=True, help="Output RKNN model path")
    parser.add_argument("--target", default="rk3588", help="RKNN target platform, e.g. rk3588/rk3566/rk3568/rk3576")
    parser.add_argument("--input-name", default="input", help="ONNX input tensor name")
    parser.add_argument("--input-size", default="1,705", help="Input shape, default: 1,705")
    parser.add_argument("--opt-level", type=int, default=3, help="RKNN optimization level")
    parser.add_argument("--quantize", action="store_true", help="Enable INT8 quantization")
    parser.add_argument("--dataset", default="", help="Quantization dataset txt path")
    parser.add_argument("--verbose", action="store_true", help="Enable verbose log")
    args = parser.parse_args()

    try:
        from rknn.api import RKNN
    except Exception as e:
        print("[ERROR] Cannot import rknn.api.")
        print("Reason:", e)
        print()
        print("Please install RKNN-Toolkit2 first.")
        print("For many Rockchip workflows, conversion is done on an Ubuntu PC with rknn-toolkit2,")
        print("then the generated .rknn is copied to the board for deployment.")
        sys.exit(1)

    onnx_path = os.path.abspath(os.path.expanduser(args.onnx))
    output_path = os.path.abspath(os.path.expanduser(args.output))

    if not os.path.exists(onnx_path):
        print("[ERROR] ONNX model not found:", onnx_path)
        sys.exit(1)

    os.makedirs(os.path.dirname(output_path), exist_ok=True)

    input_size = parse_input_size(args.input_size)

    print("========== ONNX -> RKNN ==========")
    print("ONNX model :", onnx_path)
    print("RKNN output:", output_path)
    print("Target     :", args.target)
    print("Input name :", args.input_name)
    print("Input size :", input_size)
    print("Quantize   :", args.quantize)
    print("==================================")

    rknn = RKNN(verbose=args.verbose)

    print("--> Config RKNN")
    ret = rknn.config(
        target_platform=args.target,
        optimization_level=args.opt_level
    )
    if ret != 0:
        print("[ERROR] rknn.config failed, ret =", ret)
        rknn.release()
        sys.exit(ret)

    print("--> Load ONNX")
    load_kwargs = {
        "model": onnx_path,
    }

    if input_size is not None:
        load_kwargs["inputs"] = [args.input_name]
        load_kwargs["input_size_list"] = [input_size]

    ret = rknn.load_onnx(**load_kwargs)
    if ret != 0:
        print("[ERROR] rknn.load_onnx failed, ret =", ret)
        rknn.release()
        sys.exit(ret)

    print("--> Build RKNN")
    if args.quantize:
        if not args.dataset:
            print("[ERROR] Quantization enabled, but --dataset is empty.")
            rknn.release()
            sys.exit(1)

        dataset_path = os.path.abspath(os.path.expanduser(args.dataset))
        if not os.path.exists(dataset_path):
            print("[ERROR] Dataset file not found:", dataset_path)
            rknn.release()
            sys.exit(1)

        ret = rknn.build(
            do_quantization=True,
            dataset=dataset_path
        )
    else:
        ret = rknn.build(
            do_quantization=False
        )

    if ret != 0:
        print("[ERROR] rknn.build failed, ret =", ret)
        rknn.release()
        sys.exit(ret)

    print("--> Export RKNN")
    ret = rknn.export_rknn(output_path)
    if ret != 0:
        print("[ERROR] rknn.export_rknn failed, ret =", ret)
        rknn.release()
        sys.exit(ret)

    rknn.release()

    print("========== DONE ==========")
    print("RKNN model saved to:")
    print(output_path)


if __name__ == "__main__":
    main()
