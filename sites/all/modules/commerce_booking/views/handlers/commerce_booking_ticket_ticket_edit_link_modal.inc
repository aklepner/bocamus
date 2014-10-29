<?php
/**
 * @file
 * Contains a Views field handler to a link to the edit ticket modal
 */

class commerce_booking_ticket_ticket_edit_link_modal extends views_handler_field {

  /**
   * Overrides views_handler_field::construct().
   */
  function construct() {
    parent::construct();

    $this->additional_fields['ticket_id'] = 'ticket_id';
  }

  /**
   * Overrides views_handler_field::option_definition().
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['text'] = array('default' => '', 'translatable' => TRUE);

    return $options;
  }

  /**
   * Overrides views_handler_field::options_form().
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
  }

  /**
   * Overrides views_handler_field::query().
   */
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Overrides views_handler_field::render().
   */
  function render($values) {
    // Include everything we need for our CTools modals.
    ctools_include('modal');
    ctools_include('ajax');
    ctools_modal_add_js();
    ctools_add_js('ajax-responder');
    drupal_add_js(array(
      'CToolsModal' => array(
        'modalSize' => array(
          'type' => 'fixed',
          'width' => 500,
          'height' => 450,
        ),
      ),
    ), 'setting');

    $ticket_id = $values->{$this->aliases['ticket_id']};
    $text = !empty($this->options['text']) ? $this->options['text'] : t('Edit');

    return l(t($text), 'commerce_booking/ticket/' . $ticket_id . '/edit/nojs', array(
            'attributes' => array(
              'class' => array('ctools-use-modal'),
            ),
            'query' => array(
              'destination' => current_path(),
            ),
          ));
  }
}