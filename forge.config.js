const config = {
  hooks: {
    postPackage: require('./src/hooks/notarize.js')
  },
  packagerConfig: {
    asar: true,
    osxSign: {
			"hardened-runtime": true,
      "gatekeeper-assess": false,
      "entitlements": "./static/entitlements.plist",
      "entitlements-inherit": "./static/entitlements.plist",
			"identity": "Developer ID Application: VICREO BV (XS47984U9A)"
    },
		"icon": "./src/img/icon.icns"
	},
  makers: [
    {
      name: "@electron-forge/maker-squirrel",
      config: {
        name: "vicreo_listener",
      },
    },
    {
      name: "@electron-forge/maker-zip",
			platforms: ["darwin"],
    },
    {
      name: "@electron-forge/maker-deb",
      config: {},
    },
    {
      name: "@electron-forge/maker-rpm",
      config: {},
    },
  ],
};

module.exports = config;
