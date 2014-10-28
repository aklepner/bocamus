<?php

/**
 * @file
 * Views field handler to display a download link for a line item's tickets.
 */

class commerce_event_ticket_pdf_views_handler_field_link_line_item extends commerce_event_ticket_pdf_views_handler_field_link_order {

  protected $entity_type = 'commerce_line_item';

}
