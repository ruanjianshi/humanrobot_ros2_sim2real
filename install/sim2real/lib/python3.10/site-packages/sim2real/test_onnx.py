import os
import numpy as np

from .inference import ONNXPolicy


def main():
    model_path = os.path.expanduser(
        "~/Desktop/ros2_simreal_ws/src/sim2real/policy/walk_policy.onnx"
    )

    if not os.path.exists(model_path):
        print("[ERROR] ONNX model not found:")
        print(model_path)
        print("Please copy walk_policy.onnx to src/sim2real/policy/")
        return

    policy = ONNXPolicy(model_path)

    input_shape = policy.input_shape
    obs_dim = input_shape[-1]

    obs = np.zeros((1, obs_dim), dtype=np.float32)

    action, infer_ms = policy.infer(obs)

    print("obs shape:", obs.shape)
    print("action shape:", action.shape)
    print("action min:", action.min())
    print("action max:", action.max())
    print("infer ms:", infer_ms)


if __name__ == "__main__":
    main()
