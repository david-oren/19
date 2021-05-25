" vimrc

scriptencoding utf-8
set encoding=utf-8
colorscheme ron
set autoread
set autowrite
if !isdirectory($HOME . '/.vim/backup')
  call mkdir($HOME . '/.vim/backup')
endif
set backupext=~                 " backup file extension
set backupdir=$HOME/.vim/backup// " directory of backups
set backupcopy=yes              " keep attributes of the original file
set backup                      " save files after close
set writebackup                 " make a backup of the original file when writing
set directory=$HOME/.vim/backup//
set undodir=$HOME/.vim/backup//
set mouse=a
set cc=80
set shiftwidth=2
set tabstop=2
syntax on
filetype plugin on
filetype plugin indent on
set cindent
set autoindent
set ruler
set number
set showcmd
set showmode
set incsearch
set hlsearch
set wildmenu
set list
set listchars=tab:->,trail:-,eol:$
set backspace=indent,eol,start
set pastetoggle=<F2>

let mapleader = ","
nnoremap <leader>s :wa<CR>
nnoremap <leader>h :Stdheader<CR>
nnoremap <leader>tv :tabe $MYVIMRC<CR>
nnoremap <leader>r :source $MYVIMRC<CR>
nnoremap <leader>tz :tabe ~/.zshrc<CR>
nnoremap <leader>tt :tabe ~/.tmux.conf<CR>

function! ToggleRNU()
 if &rnu == 0
  set rnu
  echo "set relativenumber"
 else
  set nornu
  echo "set norelativenumber"
 endif
endfunction
nnoremap <leader>n :call ToggleRNU()<CR>

function! ToggleList()
 if &list == 1
  set nolist
  echo "set nolistchars"
 else
  set list
  echo "set listchars"
 endif
endfunction
nnoremap <leader>i :call ToggleList()<CR>
nnoremap <C-a> : 24 Vexplore<CR>

