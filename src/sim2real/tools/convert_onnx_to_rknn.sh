#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PKG_DIR="$(cd "${SCRIPT_DIR}/.." && pwd)"

DEFAULT_ONNX="${PKG_DIR}/policy/walk_policy.onnx"
DEFAULT_RKNN="${PKG_DIR}/policy/walk_policy.rknn"

ONNX_MODEL="${1:-${DEFAULT_ONNX}}"
RKNN_MODEL="${2:-${DEFAULT_RKNN}}"
TARGET_PLATFORM="${3:-rk3588}"
INPUT_SIZE="${4:-1,705}"
INPUT_NAME="${5:-input}"

echo "========== RKNN Convert Script =========="
echo "Package dir     : ${PKG_DIR}"
echo "ONNX model      : ${ONNX_MODEL}"
echo "RKNN output     : ${RKNN_MODEL}"
echo "Target platform : ${TARGET_PLATFORM}"
echo "Input name      : ${INPUT_NAME}"
echo "Input size      : ${INPUT_SIZE}"
echo "========================================="

if [ ! -f "${ONNX_MODEL}" ]; then
    echo "[ERROR] ONNX model not found:"
    echo "${ONNX_MODEL}"
    exit 1
fi

python3 - <<'PY'
import sys
try:
    from rknn.api import RKNN
except Exception as e:
    print("[ERROR] Python cannot import rknn.api")
    print("Reason:", e)
    print()
    print("Please install RKNN-Toolkit2 first.")
    print("This script only performs conversion after rknn-toolkit2 is available.")
    sys.exit(1)
print("[OK] rknn.api is available")
PY

python3 "${SCRIPT_DIR}/onnx2rknn.py" \
    --onnx "${ONNX_MODEL}" \
    --output "${RKNN_MODEL}" \
    --target "${TARGET_PLATFORM}" \
    --input-name "${INPUT_NAME}" \
    --input-size "${INPUT_SIZE}"

echo
echo "========== Output =========="
ls -lh "${RKNN_MODEL}"
echo "RKNN conversion finished."
