function do_test(){
    for ((i=0;i<30;i++)); do
        python grpctry.py >> out
    done
}

for ((i=0;i<3;i++)); do
    do_test &
done

wait