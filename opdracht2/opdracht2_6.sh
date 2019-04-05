    
#print willekeurig de letters van het meegegeven woord door (bijv. met ./opdracht2_6.sh woord)
string=$1
stringLength=$(echo $string | wc -m)

RANDOM=$$
while :; do
        randomNum=$(( $RANDOM % $stringLength ))
        randomChar=${1:$randomNum:1}
        printf "%*s" $randomNum $randomChar
        sleep 0.01
done