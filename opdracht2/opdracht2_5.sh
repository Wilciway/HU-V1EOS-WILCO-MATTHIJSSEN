echo "Wat is je naam?"
read naam
if [ -z $naam  ]
then
naam=$(whoami)
fi

wachtwoord="niet"
wachtwoordCheck="hetzelfde"
touch $1
while [ "$wachtwoord" != "$wachtwoordCheck" ]
do
        echo "vul uw wachtwoord in"
        read wachtwoord
        echo "vul uw wachtwoord opnieuw in"
        read wachtwoordCheck
done
echo "$naam $wachtwoord" >> $1
echo -n $wachtwoord | md5sum >> $1