pipeline {
  agent any
  stages {
    stage('Build') {
      steps {
        //   cmakeBuild(
        //     installation: 'InSearchPath'
        //   )
        sh 'echo "Building..."'
        sh 'chmod +x /home/pi/Documents/Projects/Face-operated-door-lock/Version_1/installer.sh'
        sh 'bash /home/pi/Documents/Projects/Face-operated-door-lock/Version_1/installer.sh'
        archiveArtifacts artifacts: '/home/pi/Documents/Projects/Face-operated-door-lock/Version_1/out/build/*', fingerprint: true
      }
    }
    stage('Test') {
      steps {
        //   cmakeBuild(
        //     installation: 'InSearchPath'
        //   )
        sh 'echo "Running..."'
        sh 'chmod +x /home/pi/Documents/Projects/Face-operated-door-lock/Version_1/run.sh'
        sh 'bash /home/pi/Documents/Projects/Face-operated-door-lock/Version_1/run.sh'
      }
    }
  }
}