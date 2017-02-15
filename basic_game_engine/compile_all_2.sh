#!/bin/bash

files=$(ls)


function get_h_cpp {

    # this function returns the file name if its a .h/.cpp  file 
    # otherwise it returns a empty string like ''

    if [[ $1 == *.cpp ]] || [[ $1 == *.h ]]
    then
        echo $1
    else
        echo ''
    fi

}


function get_compile_files {

    # all the information we need to start the getting the files.

    current_dir=$1
    h_cpp_files=''
    files=$(ls $current_dir)  

    for file in $files
    do
        temp=$(get_h_cpp $file)

        # if the file is .h or .cpp only then we will save the file name.

        if [[ $temp != '' ]]
        then
            absolute_path=$current_dir/$file   # note here we are using absolute path so that we can use recursion.
            h_cpp_files="$h_cpp_files $absolute_path"
        else
            if [ -d $file  ]
            then

                # if this is a dir then we use a recursion to get
                # all the files(.h and .cpp) from this dir
                sub_dir_files=$(get_compile_files $current_dir/$file)
                h_cpp_files="$h_cpp_files $sub_dir_files"
            fi
        fi

    done

    echo  $h_cpp_files 


}

current_dir=$(pwd)

compile_files=$(get_compile_files $current_dir)


g++ $compile_files -o test -std=c++11  -lsfml-graphics -lsfml-window -lsfml-system
