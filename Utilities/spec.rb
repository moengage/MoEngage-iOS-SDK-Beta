require 'fileutils'
require 'json'
require 'ostruct'

module MoEngageSDKBeta
  module Spec
    def define()
      podspec_path = caller.find do |trace|
        File.extname(trace.split(":")[0]).eql?('.podspec')
      end.split(":")[0]

      podspec = File.basename(podspec_path, File.extname(podspec_path))
      config = JSON.parse(File.read('package.json'), {object_class: OpenStruct})
      package_index = config.packages.find_index { |package| package.name == podspec }
      package = config.packages[package_index] if package_index

      self.name              = podspec
      self.version           = package&.version || config.version
      self.homepage          = 'https://www.moengage.com'
      self.documentation_url = 'https://developers.moengage.com'
      self.license           = { :type => 'Commercial', :file => 'LICENSE' }
      self.author            = { 'MobileDev' => 'mobiledevs@moengage.com' }
      self.social_media_url  = 'https://twitter.com/moengage'

      self.source       = {
        :git => 'https://github.com/moengage/MoEngage-iOS-SDK-Beta.git',
        :tag => "#{package&.tagPrefix || config.tagPrefix}#{self.version.to_s}"
      }

      self.ios.deployment_target = '11.0'
      self.requires_arc = true
      self.vendored_frameworks = "Frameworks/#{package.framework}.xcframework" if package
      self.preserve_paths = "*.md", "LICENSE"
    end

    def addDirectUseWarning()
      self.description << '\nDO NOT USE THIS POD DIRECTLY, USE MoEngage-iOS-SDK INSTEAD THAT INCLUDES THIS POD'
    end
  end
end