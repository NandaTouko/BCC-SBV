<?php

namespace App\Controller;

use FW\Controller\Action;

class WidgetsController extends Action{

    public function smallBox(){
        $title = "Small Box";
        $title_pagina = "Small Box";        

        $this->getView()->title = $title;
        $this->getView()->title_pagina = $title_pagina;

        $this->render('small-box/index', 'dashboard');
    }

    public function infoBox(){
        $title = "Info Box";
        $title_pagina = "Info Box";        

        $this->getView()->title = $title;
        $this->getView()->title_pagina = $title_pagina;

        $this->render('info-box/index', 'dashboard');
    }

    public function cards(){
        $title = "Cards";
        $title_pagina = "Cards";        

        $this->getView()->title = $title;
        $this->getView()->title_pagina = $title_pagina;

        $this->render('cards/index', 'dashboard');
    }

    public function validaAutenticacao() {}
}

?>