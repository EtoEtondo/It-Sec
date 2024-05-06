#!/bin/bash

usage(){
	echo "Usage: $0 ./md5_password_re.sh <list> <hashes>"
	exit 1
}

if [ $# -ne 2 ];then
	usage
fi

rm tmp.txt

echo hist, passwort, MD5 hash
for i in $(cat $1);do
	worthashed=$(echo -n $i | md5sum)
	wrthsh=$(echo $worthashed | cut -d " " -f 1)
	same=$(grep $wrthsh $2 | wc -w)
		if [ same ];then

			echo $same, \"$i\", $wrthsh #>> tmp.txt	
		fi
done | sort -n -r

#sort -n -r tmp.txt
