<?php

namespace App\Controller;

use FW\Controller\Action;

class UIController extends Action{

    public function general(){
        $title = "General";
        $title_pagina = "General";        

        $this->getView()->title = $title;
        $this->getView()->title_pagina = $title_pagina;

        $this->render('general/index', 'dashboard');
    }

    public function timeline(){
        $title = "Timeline";
        $title_pagina = "Timeline";        

        $this->getView()->title = $title;
        $this->getView()->title_pagina = $title_pagina;

        $this->render('timeline/index', 'dashboard');
    }

    public function validaAutenticacao() {}
}

?>