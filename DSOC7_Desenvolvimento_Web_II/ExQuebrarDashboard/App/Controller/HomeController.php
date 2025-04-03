<?php

namespace App\Controller;

use FW\Controller\Action;

class HomeController extends Action{

    public function index(){
        $title = "home";
        $title_pagina = "home";       

        $this->getView()->title = $title;
        $this->getView()->title_pagina = $title_pagina;

        $this->render('index', 'dashboard');
    }

    public function validaAutenticacao() {}
}
