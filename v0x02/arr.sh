for file in solutions/*.cpp; do
  dir="solutions/${file%%.*}" # 파일 이름에서 확장자를 제외한 부분을 추출하여 폴더 이름으로 사용
  mkdir -p "$dir" # 동일한 이름의 폴더 생성 (-p 옵션은 폴더가 이미 존재하는 경우 오류를 방지)
  mv "$file" "$dir" # 파일을 해당 폴더로 이동
done