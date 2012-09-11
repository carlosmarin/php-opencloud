<?php
// (c)2012 Rackspace Hosting
// See COPYING for licensing information

namespace OpenCloud\DbService;

require_once('collection.inc');
require_once('instance.inc');

/**
 * InstanceList is a Collection of Database instances
 *
 * @author Glen Campbell <glen.campbell@rackspace.com>
 */
class InstanceList extends \OpenCloud\Collection {
	/**
	 * Retrieves the next instance in the list, uses factory to produce object
	 */
	public function Next() {
		$item = parent::Next();
		if ($item) {
			return $this->Service()->Instance($item);
		}
		else
			return FALSE;
	} // function Next()
}