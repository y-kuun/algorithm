/*
 * Complete the function below.
 */
int get_second_most_freq(vector<int> the_list) {
    if (the_list.size() == 0) {
        return 0;
    }

    sort(the_list.begin(), the_list.end());
    int max = -1;
    int loc;
    int sec_max = -1;
    int sec_loc;
    int tmp = 1;
    int cur_num = the_list[0];
    for (int i = 1; i < the_list.size(); i++) {
        if (the_list[i] == cur_num) {
            tmp++;
        } else {
            if (max < tmp) {
                sec_max = max;
                sec_loc = loc;
                max = tmp;
                loc = the_list[i - 1];
            } else if (sec_max > tmp) {
                sec_max = tmp;
                sec_loc = the_list[i - 1];
            }
            cur_num = the_list[i];
            tmp = 1;
        }
    }
    if (max < tmp) {
        sec_max = max;
        sec_loc = loc;
        max = tmp;
        loc = the_list[the_list.size() - 1];
    } else if (sec_max > tmp) {
        sec_max = tmp;
        sec_loc = the_list[the_list.size() - 1];
    }
    return sec_loc;
}
