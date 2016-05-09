// Import libs
import $ from 'jquery';
import '../../node_modules/semantic-ui-css/semantic';

(function () {
  // Run when DOM is ready
  $(function () {
    /*
    $(window).on('dialog:beforecreate', (event, dialog, element, settings) => {
      "use strict";

      settings.dialogClass = 'ui modal';
      settings.buttonClass = 'button';
      settings.buttonPrimaryClass = 'primary';

      element.addClass('content');
    });

    $(window).on('dialog:aftercreate', (event, dialog, element, settings) => {
      "use strict";
      element.siblings('.ui-dialog-titlebar').addClass('header');
    });
    */
  });

  // Run when DOM is changed
  Drupal.behaviors.oddAdmin = {
    attach(context) {
      $('.ui.checkbox', context).checkbox();
      $('.ui.dropdown', context).dropdown();
    }
  };
})();
