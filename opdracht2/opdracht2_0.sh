mkdir -p $1/Afbeeldingen/
find $1 -name "*.png" -o "*.jpeg" -exec mv {} /&1/Afbeeldingen/ \;