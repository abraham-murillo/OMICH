compile() {
  # Compiles 'filename' with g++ and using 'moreFlags'
  file=$1
  filename="${file%.*}"

  moreFlags=""
  if [ $# -ge 2 ]; then
    moreFlags=$2
  fi

  alias flags='-Wall -Wextra -w -mcmodel=large'
  g++ --std=c++17 ${moreFlags} ${flags} ${filename}.cpp -o ${filename}.out 
}

go() {
  flags=$1
  file=$2
  input=$3
  filename="${file%.*}"

  compile ${filename} ${flags}
  
  ./${filename}.out < ${input}

  rm ${filename}.out
}

run() {
  go "" $1 $2
}

debug() {
  go -DLOCAL $1 $2
} 