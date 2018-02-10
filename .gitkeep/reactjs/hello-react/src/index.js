// import React from 'react';
// import ReactDOM from 'react-dom';
// import './index.css';
// import App from './App';
// import registerServiceWorker from './registerServiceWorker';

// ReactDOM.render(<App />, document.getElementById('root'));
// registerServiceWorker();

import React, {Component} from 'react'
import ReactDOM from 'react-dom'
import './index.css'

class LikeButton extends Component {
    constructor () {
      super()
      this.state = { isLiked: false }
    }
  
    handleClickOnLikeButton () {
      this.setState({
        isLiked: !this.state.isLiked
      })
    }
  
    render () {
        const likedText = this.props.likedText || '取消'
        const unlikedText = this.props.unlikedText || '点赞'
        return (
          <button onClick={this.handleClickOnLikeButton.bind(this)}>
            {this.state.isLiked ? likedText : unlikedText} 👍
          </button>
        )
    }
  }
class Title extends Component {
    handleClickOnTitle (word,e) {
        console.log(word)
        console.log(this)
        console.log(e.target.innerHTML)
      }
    
      render () {
        return (
          <h1 onClick={this.handleClickOnTitle.bind(this,'hello')}>React 小书</h1>
        )
      }
  }
  
  class Header extends Component {
    render () {
      return (
      <div>
        <Title />
        <h2>This is Header</h2>
      </div>
      )
    }
  }
  
  class Main extends Component {
    render () {
      return (
      <div>
        <h2>This is main content</h2>
      </div>
      )
    }
  }
  
  class Footer extends Component {
    render () {
      return (
      <div>
        <h2>This is footer</h2>
      </div>
      )
    }
  }
  
  class Index extends Component {
    render () {
      return (
        <div>
        <LikeButton likedText='已赞' unlikedText='赞' />
        </div>
      )
    }
  }

ReactDOM.render(
    <Index />,
    document.getElementById('root')
)