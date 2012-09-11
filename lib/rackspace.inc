<?php
// (c)2012 Rackspace Hosting
// See COPYING for licensing information

namespace OpenCloud;

require_once('openstack.inc');
require_once('dbservice.inc');

/**
 * Rackspace extends the OpenStack class with support for Rackspace's
 * API key and tenant requirements.
 *
 * The only difference between Rackspace and OpenStack is that the
 * Rackspace class generates credentials using the username,
 * tenantName (ID), and API key, as required by the Rackspace authentication
 * service.
 *
 * Example:
 * <code>
 * $username = 'FRED';
 * $tenant = '1234560';
 * $apiKey = '0900af093093788912388fc09dde090ffee09';
 * $conn = new Rackspace(
 *      'http://identity.rackspace.com/v2/',
 *      array(
 *          'username' => $username,
 *          'tenantName' => $tenant,
 *          'apiKey' => $apiKey
 *      ));
 * </code>
 */
class Rackspace extends OpenStack {
//this is the JSON string for our new credentials
const APIKEYTEMPLATE = <<<ENDCRED
{ "auth": { "RAX-KSKEY:apiKeyCredentials": { "username": "%s",
          "tenantName": "%s",
          "apiKey": "%s"
        }
    }
}
ENDCRED;

	/**
	 * Generates Rackspace API key credentials
	 */
    public function Credentials() {
    	$sec = $this->Secret();
        return sprintf(
            self::APIKEYTEMPLATE,
            $sec['username'],
            $sec['tenantName'],
            $sec['apiKey']
       );
    }

    /**
     * Creates a new DbService (Database as a Service) object
     *
     * This is a factory method that is Rackspace-only (NOT part of OpenStack).
     *
     * @param string $name
     * @param string $region
     * @param string $urltype
     */
    public function DbService($name=NULL, $region=NULL, $urltype=NULL) {
        return $this->Service('DbService', $name, $region, $urltype);
    }


} // end class Rackspace