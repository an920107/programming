# select id, real_name, oi_problems_status from user_profile where (oi_problems_status->'problems'->'1' is NULL) or oi_problems_status->'problems'->'1'->>'status' != '0';

for i in range(1, 14):
    print("select id, real_name, oi_problems_status->'problems'->'%d'\
        from user_profile where (oi_problems_status->'problems'->'%d' is NULL)\
        or oi_problems_status->'problems'->'%d'->>'status' != '0';\n" % (i, i, i))