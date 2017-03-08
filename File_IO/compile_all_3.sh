

TRUE=0
FALSE=1

function is_h_cpp {

    file=$1

    if [[ $file == *.h ]] || [[ $file == *.cpp ]] || [[ $file == *.hpp ]]
    then
        return $TRUE
    else
        return $FALSE
    fi


}

complile_file=""

function create_structure {

    files=$(ls $1)

    for file in $files
    do

        current="$1/$file"

        if [ -d $current ]
        then
            create_structure $current

        elif is_h_cpp $current
        then
            complile_file="$complile_file $current"

        fi

    done
}

dir=$(pwd)
create_structure $dir

g++ $complile_file -std=c++11 -o test
