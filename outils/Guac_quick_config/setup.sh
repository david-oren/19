printf "\033[32m= = = SETUP = = =\n\033[m"
cd ~
printf "\033[32m+ + + OMZSH + + +\n\033[m"

sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)" "" --unattended

printf "\033[32m+ + + P10K + + +\n\033[m"
git clone --depth=1 https://github.com/romkatv/powerlevel10k.git ~/powerlevel10k

printf "\033[33m> > > BKP + + +\n\033[m"
mv .zshrc .old.zshrc
mv .p10k.zsh .old.p10k.zsh

clear
printf "\033[34mV V V DOWNLOAD DOT FILES V V V\n\033[m"

curl -s https://raw.githubusercontent.com/lorenuars19/Guac_quick_config/master/zshrc -o ~/.zshrc > /dev/null
printf "\033[32m+ + + .zshrc \033[m\n"
curl -s https://raw.githubusercontent.com/lorenuars19/Guac_quick_config/master/p10k-zsh -o ~/.p10k.zsh /dev/null
printf "\033[32m+ + + .p10k.zsh \033[m\n"
curl -s https://raw.githubusercontent.com/lorenuars19/Guac_quick_config/master/vimrc -o ~/.vimrc > /dev/null
mkdir -p .vim
printf "\033[32m+ + + .vimrc \033[m\n"

printf "\033[34mV V V SOURCE V V V\n\033[m"
source ~/.zshrc > /dev/null 2>&1

printf "\033[35m+ + + SSH + + +\n\033[m"

ssh-keygen

clear
printf "\n\n\033[33m"
cat ~/.ssh/id_rsa.pub

printf "\n\n\033[m"


git clone --depth=1 https://github.com/Homebrew/brew $HOME/.brew && echo 'export PATH=$HOME/.brew/bin:$PATH' >> $HOME/.zshrc && source $HOME/.zshrc && brew update

