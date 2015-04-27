<?php

class ProfileStreamWrapper extends DrupalLocalStreamWrapper {
/**
   * Get profile name of the current URI.
   */
  protected function getSystemName($uri = NULL) {
    if (!isset($uri)) {
      $uri = $this->uri;
    }
    list($scheme, $target) = explode('://', $uri, 2);
    $pos = strpos($target, '/');
    return $pos === FALSE ? $target : substr($target, 0, $pos);
  }

  protected function getTarget($uri = NULL) {
    if (!isset($uri)) {
      $uri = $this->uri;
    }

    list($scheme, $target) = explode('://', $uri, 2);

    // Remove erroneous leading or trailing, forward-slashes and backslashes.
    $target = trim($target, '\/');

    // Remove the module/theme/profile name form the file path.
    $target = substr($target, strlen($this->getSystemName()));

    // Trim again.
    $target = trim($target, '\/');

    return $target;
  }

  public function getDirectoryPath() {
    return 'profiles/' . $this->getSystemName();
  }

  public function getExternalUrl() {
    return url('profiles/' . $this->getSystemName());
  }
}