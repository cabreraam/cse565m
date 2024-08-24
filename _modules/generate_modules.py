import subprocess

for week in range(2,15):
    if week < 10: 
        week_num = '0' + str(week)
    else:
        week_num = str(week)
    new_fname = 'week-' + week_num + '.md'
    process = subprocess.run(['cp', 'week-01a.md', new_fname], stdout=subprocess.PIPE, universal_newlines=True)

    print(f'{process.stdout}')
