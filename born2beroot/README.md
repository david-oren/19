Ce projet a pour but de vous faire découvrir le merveilleux monde de la virtualisation.
Vous allez créer votre première machine en respectant des consignes précises et en
utilisant VirtualBox (ou UTM si VirtualBox ne fonctionne pas sur votre machine). Ainsi,
à la suite de ce projet, vous serez capable d’installer votre propre système d’exploitation
implémentant des règles strictes.

Install 
Telecharge version stable:
https://www.debian.org/

VM:
Nouvelle: ok pour tous
Config: reseau --> acces par pont
Stockage --> Debian --> choisir iso debian

Lancer Debian:

1. instalation
Suivre les etapes d installation
Nom de la machine --> login42
domain --> enter
choisir mot de passe root
nom complet nouvel utilisateur: login
choisir mot de passe user
partion: Assiste chiffre --> partion /home separe --> ecrire modif oui 
Quantite d espace 7.5 GB
terminer le partionenement --> oui et faut il analyser un autre cd non
Belgique --> debian --> enter
Aller sur serveur ssh et faite enter
installer grub et choisir /dev/sda......
Connectez vous en root

SSH
apt-get update
apt-get install openssh-server
nano /etc/ssh/sshd_config
#Port 22 --> Port 4242
#PermitRootLogin prohibit-password --> PermitRootLogin yes 

UFW
apt-get install ufw
sudo ufw enable
sudo ufw default deny incoming
sudo ufw default allow outgoing
sudo ufw allow 4242
Puis pour check
sudo ufw status

groupe user
Cet utilisateur appartiendra aux groupes user42 et sudo --> usermod -a -G examplegroup exampleusername

Un utilisateur sera présent avec pour nom votre login en plus de l’utilisateur root.


Politique de mot de passe forte:
apt-get -y install libpam-pwquality cracklib-runtime

nano /etc/login.defs
--> PASS_MAX_DAYS 30
--> PASS_MIN_DAYS 2

/etc/pam.d/common-password
difok=N    Nombre de caractères du nouveau mot de passe qui ne sont pas présents dans l'ancien, par défaut difok=1
minlen=N    Taille minimum du nouveau mot de passe. Cependant un bonus d'un caractère en plus est rajouté si un type de caractères différent de plus est présent dans le mot de passe.
dcredit=N    Si dcredit < 0, dcredit est l'opposé du nombre minimum de chiffres dans le nouveau mot de passe, exemple si dcredit = -5, il faut au moins 5 chiffres dans le mot de passe.
ucredit=N    Si ucredit < 0, ucredit est l'opposé du nombre minimum de lettres majuscules dans le nouveau mot de passe, exemple si ucredit = -4, il faut au moins 4 lettres majuscules dans le mot de passe
maxrepeat=N    Si maxrepeat=N, alors un caractère ne pourra pas être présent plus de N fois

Cron:
crontab -e select nano
--> rajouter une derniere ligne pour que le script s active toute les dix minutes
*/10 * * * * bash monitoring.sh

Sudo:
apt-get install sudo
nano /etc/sudoers
rajouter:
DEFAULT	passwd_tries=3  --> L’authentification en utilisant sudo sera limitée à 3 essais en cas de mot de passe erroné.
DEFAULT	badpass_message="bouh" --> • Un message de votre choix s’affichera en cas d’erreur suite à un mauvais mot de passe lors de l’utilisation de sudo.
DEFAULT	logfile="/var/log/sudo" --> Le journal se trouvera dans le dossier /var/log/sudo/.
DEFAULT	log_input,log_output --> • Chaque action utilisant sudo sera archivée, aussi bien les inputs que les outputs.
DEFAULT	requiretty --> Le mode TTY sera activé pour des questions de sécurité.


usercheck=N    Si usercheck est différent de 0, vérifie si le mot de passe contient le nom de l'utilisateur $USER. Cette vérification n'est pas effectuée pour les noms d'utilisateur de moins de 3 caractères.
enforce_for_root Forcer sur le root


SCRIPT

Creer un fichier monitoring.sh
nano monitoring.sh
Exemple de script:

#!/bin/bash
var=`lvdisplay`

wall << End_Of_Message
        #Architecture: `uname -a`
        #CPU physical : `grep -c ^processor /proc/cpuinfo`
        #vCPU : `cat /proc/cpuinfo | grep processor | wc -l`
        `free -m | awk 'NR==2{printf "#Memory Usage: %s/%sMB (%.2f%%)\n", $3,$2,$3*100/$2 }'`
        `df -h | awk '$NF=="/"{printf "#Disk Usage: %.2f/%dGb (%s)\n", $3,$2,$5}'`
        #CPU load: `top -bn1 | grep load | awk '{printf "%.1f%%\t\t\n", $(NF-2)}'`
        #Last boot:`who -b |  cut -d 't' -f 3`
        #LVM use: `if [ -z "$var" ]
         then
                echo "no"
        else
                echo "yes"
        fi`
        #Connexions TCP :  `sed  </proc/net/tcp '/^ *[0-9]\+: [0-9A-F: ]\{27\} 01 /p;d' | wc -l` ESTABLISHED
        #User log: `who | cut -d " " -f 1 | sort -u | wc -l`
        #Network: IP `ip -4 addr show enp0s3 | awk '/inet/ {print $2}' | sed 's#/.*##'` (`cat /sys/class/net/$(ip route show default | awk '/default/ {print $5}')/address`)
        #Sudo : `grep -o -i COMMAND /var/log/sudo | wc -l` cmd
End_Of_Message

Verification
Partion: lsblk
ufw: ufw status
groups: groups usernam

Source
https://www.cyberciti.biz/faq/ubuntu-change-hostname-command/
https://doc.ubuntu-fr.org/useradd
https://debian-handbook.info/browse/fr-FR/stable/sect.apparmor.html
https://www.redhat.com/fr/topics/linux/what-is-selinux
https://doc.ubuntu-fr.org/lvm
