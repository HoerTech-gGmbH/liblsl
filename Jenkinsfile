def liblsl_build_steps(stage_name) {
    // Extract components from stage_name:
    def system, arch, devenv
    (system,arch,devenv) = stage_name.split(/ *&& */) // regexp for missing/extra spaces

    // checkout liblsl from version control system, the exact same revision that
    // triggered this job on each build slave
    checkout scm

    // Avoid that artifacts from previous builds influence this build
    sh "git reset --hard && git clean -ffdx"

    // Autodetect libs/compiler and build
    sh "mkdir -p build && (cd build && cmake .. -DLSL_UNIXFOLDERS=1 -DCPACK_PACKAGE_DESCRIPTION_SUMMARY='Lab Streaming Layer API' .. && make package && mkdir pack )"

    // rename debian package:
    sh "./rename_debians.sh"

    // Store debian packets for later retrieval by the repository manager
    stash name: (arch+"_"+system), includes: 'build/pack/'
}

pipeline {
    agent {label "jenkinsmaster"}
    stages {
        stage("build") {
            parallel {
                stage(                        "focal && x86_64 && liblsldev") {
                    agent {label              "focal && x86_64 && liblsldev"}
                    steps {liblsl_build_steps("focal && x86_64 && liblsldev")}
                }
                stage(                        "buster && armv7 && liblsldev") {
                    agent {label              "buster && armv7 && liblsldev"}
                    steps {liblsl_build_steps("buster && armv7 && liblsldev")}
                }
                stage(                        "bionic && x86_64 && liblsldev") {
                    agent {label              "bionic && x86_64 && liblsldev"}
                    steps {liblsl_build_steps("bionic && x86_64 && liblsldev")}
                }
                stage(                        "bionic && armv7 && liblsldev") {
                    agent {label              "bionic && armv7 && liblsldev"}
                    steps {liblsl_build_steps("bionic && armv7 && liblsldev")}
                }
                stage(                        "xenial && x86_64 && liblsldev") {
                    agent {label              "xenial && x86_64 && liblsldev"}
                    steps {liblsl_build_steps("xenial && x86_64 && liblsldev")}
                }
            }
        }
        stage("artifacts") {
            agent {label "aptly"}
            // do not publish packages for any branches except these
            when { anyOf { branch 'master'; branch 'development' } }
            steps {
                // receive all deb packages from liblsl build
                unstash "x86_64_focal"
                unstash "x86_64_bionic"
                unstash "x86_64_xenial"
                unstash "armv7_buster"
                unstash "armv7_bionic"

                // Copies the new debs to the stash of existing debs.
                sh "make -C aptly"

                build job: "/hoertech-aptly/$BRANCH_NAME", quietPeriod: 300, wait: false
            }
        }
    }
    post {
        failure {
            mail to: 'g.grimm@hoertech.de,t.herzke@hoertech.de',
            subject: "Failed Pipeline: ${currentBuild.fullDisplayName}",
            body: "Something is wrong with ${env.BUILD_URL} ($GIT_URL)"
        }
    }
}
