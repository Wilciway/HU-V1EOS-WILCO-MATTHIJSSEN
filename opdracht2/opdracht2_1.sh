    
mkdir -p  $1/Afbeeldingen/Vakantie/

find $1/Afbeeldingen/ | grep vakantie | sudo xargs -I {} mv {} $1/Afbeeldingen/Vakantie/