import './App.css';
import "../node_modules/bootstrap/dist/css/bootstrap.min.css"
import Navbar from './layout/Navbar';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import Home from './pages/Home';

function App() {
  return (
    <div className="App">
      <Router>

        <Navbar />

        <Routes>
          <Route exact path="/" element={<Home/>} />
        </Routes>


      </Router>
    </div>
  );
}

export default App;
