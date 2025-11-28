let s:cpo_save=&cpo
set cpo&vim
cnoremap <silent> <Plug>(TelescopeFuzzyCommandSearch) e "lua require('telescope.builtin').command_history { default_text = [=[" . escape(getcmdline(), '"') . "]=] }"
inoremap <C-W> u
inoremap <C-U> u
vnoremap <silent>  <Cmd>lua require('Comment.api').toggle.linewise(vim.fn.visualmode())
nnoremap <silent>  zz
nnoremap <silent>  :TmuxNavigateLeft
nnoremap <silent> 	 :bnext
nnoremap <silent> <NL> :TmuxNavigateDown
nnoremap <silent>  :TmuxNavigateUp
nnoremap <silent>  :TmuxNavigateRight
nnoremap <silent>  <Cmd> q 
nnoremap <silent>  <Cmd> w 
nnoremap <silent>  zz
nmap  d
nnoremap <silent>  :TmuxNavigatePrevious
vnoremap <silent>  <Cmd>lua require('Comment.api').toggle.linewise(vim.fn.visualmode())
nnoremap <silent>  ngs :Neotree float git_status
nnoremap <silent>  e :Neotree toggle position=left
nnoremap <silent>  lw <Cmd>set wrap!
nnoremap <silent>  tp :tabp
nnoremap <silent>  tn :tabn
nnoremap <silent>  tx :tabclose
nnoremap <silent>  to :tabnew
nnoremap <silent>  xs :close
nnoremap <silent>  se =
nnoremap <silent>  h s
nnoremap <silent>  v v
nnoremap <silent>  b <Cmd> enew 
nnoremap <silent>  x :bdelete!
nnoremap <silent>  sn <Cmd>noautocmd w 
vnoremap <silent>   <Nop>
nnoremap <silent>   <Nop>
omap <silent> % <Plug>(MatchitOperationForward)
xmap <silent> % <Plug>(MatchitVisualForward)
nmap <silent> % <Plug>(MatchitNormalForward)
nnoremap & :&&
vnoremap <silent> < <gv
vnoremap <silent> > >gv
xnoremap <silent> <expr> @ mode() ==# 'V' ? ':normal! @'.getcharstr().'' : '@'
nnoremap <silent> N Nzzzv
xnoremap <silent> <expr> Q mode() ==# 'V' ? ':normal! @=reg_recorded()' : 'Q'
nnoremap Y y$
omap <silent> [% <Plug>(MatchitOperationMultiBackward)
xmap <silent> [% <Plug>(MatchitVisualMultiBackward)
nmap <silent> [% <Plug>(MatchitNormalMultiBackward)
nnoremap \ :Neotree reveal
omap <silent> ]% <Plug>(MatchitOperationMultiForward)
xmap <silent> ]% <Plug>(MatchitVisualMultiForward)
nmap <silent> ]% <Plug>(MatchitNormalMultiForward)
xmap a% <Plug>(MatchitVisualTextObject)
omap <silent> g% <Plug>(MatchitOperationBackward)
xmap <silent> g% <Plug>(MatchitVisualBackward)
nmap <silent> g% <Plug>(MatchitNormalBackward)
nnoremap <silent> n nzzzv
vnoremap <silent> p "_dP
nnoremap <silent> x "_x
xmap <silent> <Plug>(MatchitVisualTextObject) <Plug>(MatchitVisualMultiBackward)o<Plug>(MatchitVisualMultiForward)
onoremap <silent> <Plug>(MatchitOperationMultiForward) :call matchit#MultiMatch("W",  "o")
onoremap <silent> <Plug>(MatchitOperationMultiBackward) :call matchit#MultiMatch("bW", "o")
xnoremap <silent> <Plug>(MatchitVisualMultiForward) :call matchit#MultiMatch("W",  "n")m'gv``
xnoremap <silent> <Plug>(MatchitVisualMultiBackward) :call matchit#MultiMatch("bW", "n")m'gv``
nnoremap <silent> <Plug>(MatchitNormalMultiForward) :call matchit#MultiMatch("W",  "n")
nnoremap <silent> <Plug>(MatchitNormalMultiBackward) :call matchit#MultiMatch("bW", "n")
onoremap <silent> <Plug>(MatchitOperationBackward) :call matchit#Match_wrapper('',0,'o')
onoremap <silent> <Plug>(MatchitOperationForward) :call matchit#Match_wrapper('',1,'o')
xnoremap <silent> <Plug>(MatchitVisualBackward) :call matchit#Match_wrapper('',0,'v')m'gv``
xnoremap <silent> <Plug>(MatchitVisualForward) :call matchit#Match_wrapper('',1,'v'):if col("''") != col("$") | exe ":normal! m'" | endifgv``
nnoremap <silent> <Plug>(MatchitNormalBackward) :call matchit#Match_wrapper('',0,'n')
nnoremap <silent> <Plug>(MatchitNormalForward) :call matchit#Match_wrapper('',1,'n')
nnoremap <Plug>PlenaryTestFile :lua require('plenary.test_harness').test_file(vim.fn.expand("%:p"))
vnoremap <silent> <C-/> <Cmd>lua require('Comment.api').toggle.linewise(vim.fn.visualmode())
vnoremap <silent> <C-C> <Cmd>lua require('Comment.api').toggle.linewise(vim.fn.visualmode())
vnoremap <silent> <C-_> <Cmd>lua require('Comment.api').toggle.linewise(vim.fn.visualmode())
xnoremap <Plug>(comment_toggle_blockwise_visual) <Cmd>lua require("Comment.api").locked("toggle.blockwise")(vim.fn.visualmode())
xnoremap <Plug>(comment_toggle_linewise_visual) <Cmd>lua require("Comment.api").locked("toggle.linewise")(vim.fn.visualmode())
nnoremap <silent> <C-Bslash> :TmuxNavigatePrevious
nnoremap <silent> <C-H> :TmuxNavigateLeft
nnoremap <silent> <C-J> :TmuxNavigateDown
nnoremap <silent> <C-K> :TmuxNavigateUp
nnoremap <silent> <S-Tab> :bprevious
nnoremap <silent> <Right> :vertical resize +2
nnoremap <silent> <Left> :vertical resize -2
nnoremap <silent> <Down> :resize +2
nnoremap <silent> <Up> :resize -2
nnoremap <silent> <C-U> zz
nnoremap <silent> <C-D> zz
nnoremap <silent> <C-Q> <Cmd> q 
nnoremap <silent> <C-S> <Cmd> w 
nmap <C-W><C-D> d
nnoremap <silent> <C-L> :TmuxNavigateRight
inoremap <expr>  v:lua.require'nvim-autopairs'.completion_confirm()
inoremap  u
inoremap  u
let &cpo=s:cpo_save
unlet s:cpo_save
set clipboard=unnamedplus
set completeopt=menuone,noselect
set expandtab
set formatoptions=jtq
set helplang=en
set nohlsearch
set ignorecase
set iskeyword=@,48-57,_,192-255,-
set noloadplugins
set mouse=a
set packpath=/opt/homebrew/Cellar/neovim/0.11.4/share/nvim/runtime
set pumheight=10
set runtimepath=~/.config/nvim,~/.local/share/nvim/lazy/lazy.nvim,~/.local/share/nvim/lazy/nvim-autopairs,~/.local/share/nvim/lazy/todo-comments.nvim,~/.local/share/nvim/lazy/telescope-ui-select.nvim,~/.local/share/nvim/lazy/telescope-fzf-native.nvim,~/.local/share/nvim/lazy/telescope.nvim,~/.local/share/nvim/lazy/vim-rhubarb,~/.local/share/nvim/lazy/nvim-treesitter,~/.local/share/nvim/lazy/none-ls-extras.nvim,~/.local/share/nvim/lazy/none-ls.nvim,~/.local/share/nvim/lazy/nvim-window-picker,~/.local/share/nvim/lazy/nui.nvim,~/.local/share/nvim/lazy/plenary.nvim,~/.local/share/nvim/lazy/neo-tree.nvim,~/.local/share/nvim/lazy/image.nvim,~/.local/share/nvim/lazy/indent-blankline.nvim,~/.local/share/nvim/lazy/nvim-colorizer.lua,~/.local/share/nvim/lazy/Comment.nvim,~/.local/share/nvim/lazy/alpha-nvim,~/.local/share/nvim/lazy/which-key.nvim,~/.local/share/nvim/lazy/mason-null-ls.nvim,~/.local/share/nvim/lazy/fidget.nvim,~/.local/share/nvim/lazy/mason-tool-installer.nvim,~/.local/share/nvim/lazy/mason-lspconfig.nvim,~/.local/share/nvim/lazy/mason.nvim,~/.local/share/nvim/lazy/nvim-lspconfig,~/.local/share/nvim/lazy/vim-fugitive,~/.local/share/nvim/lazy/cmp-path,~/.local/share/nvim/lazy/cmp-buffer,~/.local/share/nvim/lazy/cmp-nvim-lsp,~/.local/share/nvim/lazy/cmp_luasnip,~/.local/share/nvim/lazy/friendly-snippets,~/.local/share/nvim/lazy/LuaSnip,~/.local/share/nvim/lazy/nvim-cmp,~/.local/share/nvim/lazy/vim-sleuth,~/.local/share/nvim/lazy/gitsigns.nvim,~/.local/share/nvim/lazy/vim-tmux-navigator,~/.local/share/nvim/lazy/nvim-web-devicons,~/.local/share/nvim/lazy/vim-bbye,~/.local/share/nvim/lazy/bufferline.nvim,~/.local/share/nvim/lazy/lualine.nvim,~/.local/share/nvim/lazy/nord.nvim,/opt/homebrew/Cellar/neovim/0.11.4/share/nvim/runtime,/opt/homebrew/Cellar/neovim/0.11.4/share/nvim/runtime/pack/dist/opt/netrw,/opt/homebrew/Cellar/neovim/0.11.4/share/nvim/runtime/pack/dist/opt/matchit,/opt/homebrew/Cellar/neovim/0.11.4/lib/nvim,~/.local/state/nvim/lazy/readme,~/.local/share/nvim/lazy/indent-blankline.nvim/after,~/.local/share/nvim/lazy/mason-lspconfig.nvim/after,~/.local/share/nvim/lazy/cmp-path/after,~/.local/share/nvim/lazy/cmp-buffer/after,~/.local/share/nvim/lazy/cmp-nvim-lsp/after,~/.local/share/nvim/lazy/cmp_luasnip/after
set scrolloff=4
set shiftwidth=4
set shortmess=cTCOFtlo
set noshowmode
set showtabline=2
set sidescrolloff=8
set smartcase
set smartindent
set softtabstop=4
set splitbelow
set splitright
set statusline=%#lualine_transparent#
set noswapfile
set tabline=%!v:lua.nvim_bufferline()
set tabstop=4
set termguicolors
set timeoutlen=300
set undofile
set updatetime=250
set whichwrap=bs<>[]hl
set window=48
set nowritebackup
" vim: set ft=vim :
