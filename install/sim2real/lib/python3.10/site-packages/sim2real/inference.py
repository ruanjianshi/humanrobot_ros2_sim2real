import time
import numpy as np
import onnxruntime as ort


class ONNXPolicy:
    def __init__(self, model_path: str, num_threads: int = 1):
        sess_options = ort.SessionOptions()
        sess_options.intra_op_num_threads = num_threads
        sess_options.inter_op_num_threads = num_threads

        self.session = ort.InferenceSession(
            model_path,
            sess_options=sess_options,
            providers=["CPUExecutionProvider"]
        )

        self.input_name = self.session.get_inputs()[0].name
        self.output_name = self.session.get_outputs()[0].name

        self.input_shape = self.session.get_inputs()[0].shape
        self.output_shape = self.session.get_outputs()[0].shape

        print("[ONNX] model loaded:", model_path)
        print("[ONNX] input:", self.input_name, self.input_shape)
        print("[ONNX] output:", self.output_name, self.output_shape)

    def infer(self, obs: np.ndarray):
        if obs.dtype != np.float32:
            obs = obs.astype(np.float32)

        if obs.ndim == 1:
            obs = obs.reshape(1, -1)

        t0 = time.time()

        action = self.session.run(
            [self.output_name],
            {self.input_name: obs}
        )[0]

        infer_ms = (time.time() - t0) * 1000.0
        return action.astype(np.float32), infer_ms
