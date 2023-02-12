pipeline {
  agent any
  stages {
    stage('Build') {
      steps {
        //   cmakeBuild(
        //     installation: 'InSearchPath'
        //   )
        sh 'echo "Building..."'
        sh 'chmod +x ~/Documents/Projects/Face-operated-door-lock/Version_1/installer.sh'
        sh 'bash ~/Documents/Projects/Face-operated-door-lock/Version_1/installer.sh'
        archiveArtifacts artifacts: '~/Documents/Projects/Face-operated-door-lock/Version_1/out/build/*', fingerprint: true
      }
    }
    stage('Test') {
      steps {
        //   cmakeBuild(
        //     installation: 'InSearchPath'
        //   )
        sh 'echo "Running..."'
        sh 'chmod +x ~/Documents/Projects/Face-operated-door-lock/Version_1/run.sh'
        sh 'bash ~/Documents/Projects/Face-operated-door-lock/Version_1/run.sh'
      }
    }
  }
}