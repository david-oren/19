# Born2beRoot

</br>

Ce projet a pour but de vous faire découvrir le merveilleux monde de la virtualisation.

Vous allez créer votre première machine en respectant des consignes précises et en
utilisant VirtualBox (ou UTM si VirtualBox ne fonctionne pas sur votre machine). 

Ainsi, à la suite de ce projet, vous serez capable d’installer votre propre système d’exploitation
implémentant des règles strictes.

</br>

___Mise en place de votre VM___
--------------------------------

</br>

* Telecharger la version stable de [Debian](https://www.debian.org/)

Elle se presente sous la forme d'une image CD : un .iso que l'on va monter par la suite dans notre machine virtuelle.

Si vous souhaitez faire les bonus vous pouvez suivre cette installation ci, faites par [hanshazairi](https://github.sre.pub/hanshazairi/42-born2beroot/blob/main/README.md) : [ici](https://www.youtube.com/watch?v=2w-2MX5QrQw)

</br>
  
* Lancer la machine virtuelle (VM) VirtualBox, déjà installée sur les ordinateurs de 42 normalement:

Bouton New/Nouvelle (Ctrl + N) :

Nom de votre VM - 
Folder : dans un endroit où vous pouvez utiliser 8Go.

<blockquote>Si vous êtes à 19 vous allez saturer votre session : vous pouvez travailler de maniere temporaire dans le goinfre mais sachez que celui-ci est souvent vidé, pensez donc à exporter votre VM pour ne pas avoir de mauvaise surprise</blockquote>

Type : Linux - 
Version : Debian 64bits 	

Quantitée de RAM allouée a la machine virtuelle : 1 ou 2Go sont suffisants

Créer un disque dur virtuel maintenant (taille recommandée : 8Go) - VDI (VirtualBox Disk Image) - Dynamically allocated - Verifiez sa localisation et la taille : 8Go - Creat

Allez dans les settings de votre machine virtuelle

_Onglet STORAGE_ - Controller: IDE : Click sur le petit cd bleu en dessous, dans Attributes cliquer sur le disque bleu a coté d'Optical Drive et monter le .iso de la version de Debian 

_Onglet NETWORK_ -Enable Network Adapter : Bridged Adapter/Acces par pont (chez vous) __OU__ NAT (à 42)

_OK_

</br>

* Lancer votre VM 

</br>

__Installation de Debian__
------------------------------------

*Plus d'infos sur [Debian-handbook](https://debian-handbook.info/browse/fr-FR/stable/sect.installation-steps.html) et 
[Doc.Ubuntu](https://doc.ubuntu-fr.org/lvm)*

</br>

Verifier que le bon iso est utilisé 

<blockquote>Agrandir la fenetre avec l'onglet Video Memory - Virtual Screen : 300%

Pour vous déplacer dans la VM utilisez TAB ou les fleches, afficher le mdp : espace, confirmer : enter </blockquote>

Installation - Langue : comme vous voulez - Pays : Belgique (ou votre localisation) - Clavier : selon le votre (Etats-Unis à 42)

Configurer le réseau - Hostname/Nom de la machine : votrelogin suivi de 42, ex : wil42

Domaine : _rien_

Choisir le mdp pour la partition root & le confirmer

Nom complet nouvel utilisateur : login - Identifiant pour le compteur utilisateur : login - Mdp du nouvel utilisateur : ce que vous voulez

Partitionner les disques : Assisté - utiliser tout un disque avec LVM chiffré

Selectionner le disque dur à partitionner (termine par VBOX HARDDISK)

Partitionner /home séparée - OUI

Choisissez une chouette phrase secrete avec des chiffres, des lettres et des signes de ponctuation

Partitionner les disques : 7.5 GB

<blockquote>Verifier que vous avez bien : Groupe de volumes LVM : un volume logique home, un autre root, un autre swap

Sur votre disque dur : une partition primaire pour le boot et une autre partition logique, chiffrée</blockquote>

Terminer le partitionnement et appliquer les changements - OUI

Le systeme de base s'installe

Faut-il analyser un autre CD ou DVD ? - NON

Config. l'outil de gestion des paquets : Belgique

Miroir de l'archive Debian : deb.debian.org

Mandataire HTTP/Proxy : *vide*

Etude statistique : NON

Selection des logiciels : Cocher (avec espace) serveur SSH et utilitaires usuel du système, rien d'autre

Installer le GRUB - Sur le /dev/sda ...

Continuer

</br></br>

__SUDO__
-----------------------------------------------

*Plus d'infos sur Sudo sur [Wiki.Debian](https://wiki.debian.org/fr/sudo)*

**Installation**


Installer Sudo : `apt install sudo`

Verifier que Sudo est bien installé : `dpkg -l | grep sudo`

**Ajout d'un utilisateur**

Ajouter un utilisateur au groupe sudo (cet utilisateur pourra donc utiliser la commande sudo) : `adduser <username> sudo`

Verifier les utilisateurs du groupe sudo : `getent group sudo`

Relancer la VM avec `reboot` pour que les changements prenent effet

Vérifier qui a bien les droits sudo avec la commande `sudo -v`

**Configuration de Sudo**


<blockquote>Tous les fichiers du répertoire /etc/sudoers.d/ ne finissant pas par ~ ou ne contenant pas un . sont lus et analysés lorsque l'on utilise la commande sudo.

Pour modifier le fonctionnement de la commande sudo, l'administrateur du système ne modifie plus le fichier /etc/sudoers mais positionne des fichiers de personnalisation dans le répertoire /etc/sudoers.d.

Source : [Wiki Ubuntu-fr](https://doc.ubuntu-fr.org/sudoers)</blockquote>

Créer un nouveau fichier pour configurer sudo avec `nano /etc/sudoers.d/<filename>`

Ajouter les commandes suivantes :

Pour limiter les tentatives d'authentification à 3 dans le cas d'un mdp incorrecte :

```
Defaults        passwd_tries=3
```

Pour ajouter un message d'erreur personnalisé :

```
Defaults        badpass_message="<custom-error-message>"
```

Enregistrer l'activité des sudoers dans un fichier de log spécifique :

```
Defaults        log_host, log_year, logfile="/var/log/sudo/<filename>"
```

Pour archiver toutes les input/output de sudo dans /var/log/sudo/ :

```
Defaults        log_input,log_output
Defaults        iolog_dir="/var/log/sudo"
```
Pour forcer à ce que le sudoers ne puisse pas agir ailleurs qu'en mode console :

```
Defaults        requiretty
```
Pour restreindre les path utilisés par sudo :

```
Defaults        secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
```
</br></br>

__Configuration SSH & UFW__
------------------------------------

*Plus d'infos sur l'installation du serveur SSH sur Debian sur [Devconnected](https://devconnected.com/how-to-install-and-enable-ssh-server-on-debian-10/) et
l'installation d'UFW et mise en place du pare-feu sur [Digitalocean](https://www.digitalocean.com/community/tutorials/how-to-set-up-a-firewall-with-ufw-on-ubuntu-20-04-fr#:~:text=Vous%20pouvez%20sp%C3%A9cifier%20des%20plages,ufw%20allow%206000%3A6007%2Ftcp)*

</br>

**Installation et parametrage SSH**

Entrer votre phrase secrete

Login : root - entrer le bon mdp

<blockquote>Si vous vous etes trompé d'utilisateur vous pouvez switch avec la commande su telle que : su - root

Nous serons log en root, les commandes suivantes n'auront donc pas besoin de sudo pour fonctionner</blockquote>

* Lancer une maj des paquets : `apt-get update`

* Verifier que le serveur ssh est bien installé : `apt-get install openssh-server`

Configurer dans nano afin que le serveur ssh soit actif uniquement sur le port 4242 : `nano /etc/ssh/sshd_config`

Décommenter (-#) la ligne `#Port 22` et mettre : `Port 4242`

Décommenter (-#) la ligne `#PermitRootLogin prohibit-password` et mettre : `PermitRootLogin no`

Sortir du fichier avec Ctrl + X

<blockquote>Sauvegardez (Ecrire) bien votre fichier nano sinon vos modifications seront perdues</blockquote>

Verifier le status SSH avec `service ssh status`

Relancer la VM avec `reboot`

</br>

**Se connecter du terminal de votre ordi via SSH**

Connaitre son IP : `ip a` 

Ce qui se trouve après inet dans la partie 2

Se connecter à votre VM via le port 4242 avec `ssh <username>@<ip-adress> -p 4242`

Pour sortir de la session : `logout`

</br>

**Installation du parefeu avec UFW**

Installer ufw : `apt-get install ufw`

Activer le pare-feu : `ufw enable`

Bloquer toutes les connections venant de l'exterieur : `ufw default deny incoming`

Permettre aux applications du serveurs d'avoir acces a l'exterieur :`ufw default allow outgoing`

Configurer le pare-feu pour les connexions entrantes sur le port 4242 : `ufw allow 4242`

Verifier que tout est en ordre : `ufw status numbered`

<blockquote>Si une des regles ne vous convient pas : `ufw delete [rule_nbr]`</blockquote>

</br></br>

__Mise en place de la politique de mot de passe forte__
-----------------------------------------------

*Plus d'info sur l'autentification d'utilisateur avec PAM sur [Debian.org](https://www.debian.org/doc/manuals/securing-debian-manual/ch04s11.fr.html) et [Systutorials.com](https://www.systutorials.com/docs/linux/man/5-pwquality.conf/)*

</br>

Installer libpam-pwquality et cracklib-runtime (permet de gerer la complexité des mdp) 

`apt-get -y install libpam-pwquality cracklib-runtime`

Modifier la durée à laquelle les mdp peuvent être changés dans le fichier /etc/login.defs (définit la configuration de la suite shadow password (mots de passe cachés) pour le système.) :

`nano /etc/login.defs`

Dans la section Password aging controls indiquer le nombre de jour max au bout duquel le mdp expirera :

`PASS_MAX_DAYS 30`

Et le nombre de jour min entre deux modifications du mdp :

`PASS_MIN_DAYS 2`

Dans le fichier de configuration :

`nano /etc/pam.d/common-password`

Sur la ligne `password requisite pam_pwquality.so retry=3` ajouter les instructions suivantes :

`difok=7`    Nombre de caractères du nouveau mot de passe qui ne sont pas présents dans l'ancien, par défaut difok=1

`minlen=10`    Taille minimum du nouveau mot de passe. Cependant un bonus d'un caractère en plus est rajouté si un type de caractères différent de plus est présent dans le mot de passe. **?**

`dcredit=-1`    Si dcredit < 0, dcredit est l'opposé du nombre minimum de chiffres dans le nouveau mot de passe, exemple si dcredit = -5, il faut au moins 5 chiffres dans le mot de passe.

`ucredit=-1`    Si ucredit < 0, ucredit est l'opposé du nombre minimum de lettres majuscules dans le nouveau mot de passe, exemple si ucredit = -4, il faut au moins 4 lettres majuscules dans le mot de passe

`maxrepeat=3`    Si maxrepeat=N, alors un caractère ne pourra pas être présent plus de N fois

`reject_username` Verifie que le nom de l'utilisateur n'est pas contenu dans le mot de passe, si oui le mdp est refusé

`enforce_for_root` Pour que ces restrictions prenent effet aussi sur root

Au final votre ligne ressemblera à :

```password        requisite                       pam_pwquality.so retry=3 minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root```

Sur la ligne du dessous, apres pam_unix.so rajouter `remember=1` pour garder en memoire le dernier mot de passe utilisé et pouvoir le comparer lors de la creation d'un nouveau mdp.


Créer un nouvel utilisateur :
--

Créer un nouvel utilisateur : `adduser <username>`

Verifier qu'il a bien ete créer avec `getent passwd <username>`

Verifier le temps de validité des mots de passe grace à `sudo chage -l <username>`

Créer un nouveau groupe :
--

Créer un nouveau groupe nommé `user42`

Ajouter votre nouveau membre à ce groupe avec `adduser <username> user42`

Verifier que l'user a bien ete ajouté au groupe user 42 avec `getent group user42`

</br></br>

__AppArmor__
--

*Plus d'infos sur AppArmor : [Debian-Handbook](https://debian-handbook.info/browse/fr-FR/stable/sect.apparmor.html) et SELinux : [Debian-Handbook](https://debian-handbook.info/browse/fr-FR/stable/sect.selinux.html)*

Normalement installé par défaut, vous pouvez le télécharger avec `apt install apparmor`

Completer l'installation avec `apt install apparmor-utils`

Vérifier que le module apparmor fonctionne avec `/usr/sbin/aa-status` ou `apparmor_status`
</br>

__SCRIPT__
--

*Plus d'infos sur le shell sur [Doc-Ubuntu](https://doc.ubuntu-fr.org/projets/ecole/scripting/initiation_au_shell) et le regex sur [Regexr](https://regexr.com/), allez checker le man pour uname, lscpu, awk ... vous pouvez aussi cat les différents fichiers /proc pour voir ce qui vous interesse dans leur contenu*

Créer un fichier monitoring.sh

nano monitoring.sh

Exemple de script pour un terminal **en anglais**, si vous êtes en français ou une autre langue certaines termes changeront.

```
#!/bin/bash


MEMTOTAL=$(awk '/MemTotal/ {print $2}' /proc/meminfo) 

MEMAVAIL=$(awk '/MemAvail/ {print $2}' /proc/meminfo)

MEMUSED=$((MEMTOTAL - MEMAVAIL))

LVM=$(lsblk | awk '/root/ {print $6}')


wall << End_Of_Message
	
    #Architecture: `uname -a`

    #CPU physical: `lscpu | awk '/^CPU\(s\)/ {print $2}'`

    #vCPU : `grep -c 'processor' /proc/cpuinfo`

    `echo $MEMUSED $MEMTOTAL | awk '{printf "#Memory Usage: %d/%dMB (%.2f%%)\n", ($1/1024), ($2/1024), ($1/$2)*100}'`

    `df --total | tail -n 1 | awk '{printf "#Disk Usage: %d/%dGb (%d%%)\n", ($3/1024), ($2/1048576), $5}'`

    `awk '{print "#CPU load: "$1"%\n"}' /proc/loadavg`

    #Last boot: `who -b | awk '{print $3" "$4}'`

    #LVM use: `if [ "$LVM" = "lvm" ];
    then
      echo "yes"
    else
      echo "no"
    fi`
    
    `awk '$4=="01" {count++} END{printf "#Connexions TCP : %d ESTABLISHED\n", count}' /proc/net/tcp`

    #User log: `who | awk '{print $1}' | uniq | wc -l`

    `ip -br a show $(ip route show default | awk '{print $5}') | sed 's/\/[[:digit:]]\{1,3\}//g' | awk '{printf "#Network: IP %s (%s)\n", $3, $4}'`

    `grep -c 'COMMAND' /var/log/sudo/sudo.log | awk '{printf "#Sudo : %d cmd\n", $1}'`

End_Of_Message
```
</br></br>

Qui va fonctionner ainsi :

MEMTOTAL : recup la memoire totale

MEMAVAIL : recup la memoire non utilisée

MEMUSED : Calcul la memoire utilisée

LVM : Recupere le type de partition de /root/, qui devrait etre lvm


wall << End_Of_Message : envoie le message (tout ce qui suit jusqu'à End_Of_Message) dans la commande wall qui le fera s'afficher sur tous les terminaux actifs 

#Architecture: `uname -a` : recup l'ensemble des infos de votre OS

#CPU physical: `lscpu | awk '/^CPU\(s\)/ {print $2}'` : recup dans lscpu la 2eme colone de la ligne qui commence par CPU(s)

#vCPU : `grep -c 'processor' /proc/cpuinfo` : recup dans cpuinfo l'identifiant du CPU 

`echo $MEMUSED $MEMTOTAL | awk '{printf "#Memory Usage: %d/%dMB (%.2f%%)\n", ($1/1024), ($2/1024), ($1/$2)*100}'` : recup les valeurs de MEMUSED et MEMTOTAL, les convertit en MB ( /1024), en fait un % qui est exprimé en float a 2 decimal pret grace à (%.2f%%)

`df --total | tail -n 1 | awk '{printf "#Disk Usage: %d/%dGb (%d%%)\n", ($3/1024), ($2/1048576), $5}'` : recup dans df --total | la derniere ligne | afficher la memoire utilisee dans la 3eme colonne (/en MB) sur la memoire totale dans la 2eme colonne (/en GB) et le pourcentage total de mem utilisé, dans la 5eme colonne

`awk '{print "#CPU load: "$1"%\n"}' /proc/loadavg` : recup dans /proc/loadavg l'utilisation actuelle du CPU + %

#Last boot: `who -b | awk '{print $3" "$4}'` recup dans who les col. 3 et 4 : la date et l'heure

#LVM use: `if [ "$LVM" = "lvm" ]; 	: Compare votre type de partition(LVM) avec lvm et renvoie oui ou non 
then
echo "yes"
else
echo "no"
fi`

`awk '$4=="01" {count++} END{printf "#Connexions TCP : %d ESTABLISHED\n", count}' /proc/net/tcp`  : recup le nombre de connection TCP en comptant dans la col. 4 du /proc/net/tcp le nb de 01

#User log: `who | awk '{print $1}' | uniq | wc -l` : recup dans who la premiere colonne, une seule fois par utilisateur

`ip -br a show $(ip route show default | awk '{print $5}') | sed 's/\/[[:digit:]]\{1,3\}//g' | awk '{printf "#Network: IP %s (%s)\n", $3, $4}'` : recup l'adresse ipV4 et l'adresse MAC avec ip a | grep link/ether | awk 'print $2'

`grep -c 'COMMAND' /var/log/sudo/sudo.log | awk '{printf "#Sudo : %d cmd\n", $1}'` 

End_Of_Message


__CRON__
-----------------------------------------------

*Plus d'info sur la configuration de Cron sur [Fedora-fr.org](https://doc.fedora-fr.org/wiki/CRON_:_Configuration_de_t%C3%A2ches_automatis%C3%A9es#:~:text=La%20configuration%20de%20cron%20se,via%20la%20commande%20crontab%20%2De.)*

</br>

Ouvrir le fichier crontab avec `crontab -e`, choisir Nano

Remplacer la ligne 
```
m h  dom mon dow   command
``` 
par 

```
*/10 * * * * sh /path/to/script
```

Votre script s'activera alors toutes les 10min.

</br></br>

</br></br></br>

Tout verifier : service --status-all
__Sources__
----
https://www.cyberciti.biz/faq/ubuntu-change-hostname-command/

https://doc.ubuntu-fr.org/useradd

https://debian-handbook.info/browse/fr-FR/stable/sect.apparmor.html

https://www.redhat.com/fr/topics/linux/what-is-selinux

https://doc.ubuntu-fr.org/lvm



</br></br></br></br></br></br></br></br></br></br></br></br>

_______________________________________________________________________________________________________________________
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

nano /etc/pam.d/common-password
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

pour changer de user:
su - username
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
        #LVM use: `if [ -z "$var" ]; then
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

Rendu:
Aller dans le dossier de la vm chercher le hash


Source
https://www.cyberciti.biz/faq/ubuntu-change-hostname-command/
https://doc.ubuntu-fr.org/useradd
https://debian-handbook.info/browse/fr-FR/stable/sect.apparmor.html
https://www.redhat.com/fr/topics/linux/what-is-selinux
https://doc.ubuntu-fr.org/lvm



apt-get install sudo
sudo apt-get update
sudo apt-get upgrade
/*-------------------------*/
#CREATE AN USER | ADD TO GROUP

sudo adduser <user_name>
sudo groupadd <group_name>
sudo adduser <user_name> <group_name>
cat /etc/group
/*-------------------------*/
#THE PASSWORDS

man chage
chage -M 30 <user>
chage -W 7 <user>
chage -m 2 <user>
chage --list <user>
passwd (change password)
/*-------------------------*/
#PASSWORDS COMPLEXITY

sudo apt-get install libpam-cracklib
man pam_cracklib
vim /etc/pam.d/commom-passowrd
minlen=10
ucredit=-1
dcredit=-1
maxrepeat=3
reject_username
difok=7
/*-------------------------*/
#SUDO CONFIG

man sudoers
vim /etc/sudoers
Defaults	badpass_message="<message>"
/*-------------------------*/
#INSTALL UFW

sudo apt-get install ufw
sudo ufw allow 4242
sudo ufw enable
sudo ufw delete [rule_nbr]
sudo ufw status numbered
/*-------------------------*/
#INSTALL SSH

sudo apt install openssh-server
cd /etc/ssh et mettre le port à 4242 et no à login_with_root dans le fichier sshd_config
sudo ufw allow ssh
ssh -V
/*-------------------------*/
#INSTALL APPARMOR

sudo apt-get install apparmor
apt-get install apparmor-utils
sudo apparmor_status
