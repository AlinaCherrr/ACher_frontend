import React, {useEffect, useRef, useState } from 'react'
import './Weather.css'
import Search_icon from '../assets/search.png'
import Sunny from '../assets/icons/sun.png'
import Rainy from '../assets/icons/rain.png'
import Changeable from '../assets/icons/cloud-and-sun.png'
import Cloudy from '../assets/icons/cloud.png'
import Humidity from '../assets/icons/humidity.png'
import Wind from '../assets/icons/wind.png'
import Thunder from '../assets/icons/thunder.png'
import Snow from '../assets/icons/snow.png'
import Fog from '../assets/icons/fog.png'

const Weather = () => {

    const inputRef = useRef()

    const [weatherData, setWeatherData] = useState(false);

    const allIcons = {
        '01d': Sunny,
        '01n': Sunny,
        '02d': Changeable,
        '02n': Changeable,
        '03d': Cloudy,
        '03n': Cloudy,
        '04d': Cloudy,
        '04n': Cloudy,
        '09d': Rainy,
        '09n': Rainy,
        '10d': Rainy,
        '10n': Rainy,
        '11d': Thunder,
        '11n': Thunder,
        '13d': Snow,
        '13n': Snow,
        '50d': Fog,
        '50n': Fog
    }

    const search = async (city)=>{
        try {
            
            if(city === ''){
                alert("Enter City Name");
                return;
            }

            const url = `https://api.openweathermap.org/data/2.5/weather?q=${city}&units=metric&appid=${import.meta.env.VITE_APP_ID}`;
            
            const response = await fetch(url);
            const data = await response.json();

            if (!response.ok){
                alert(data.message);
                return;
            }


            console.log(data);

            const icon = allIcons[data.weather[0].icon] || Changeable;
            setWeatherData({
                humidity: data.main.humidity,
                windSpeed: data.wind.speed,
                temperature: Math.floor(data.main.temp),
                location: data.name,
                icon: icon
            })

         } catch (error) {    
            setWeatherData(false);
            console.error("Error in fetching weather data");
            console.log(error)
        }
    }


    useEffect(()=>{
        search("Moscow");
    },[])

  return (
    <div className='weather'>
        <div className="search-bar">
            <input ref={inputRef} type='text' placeholder='Search' />
            <img src={Search_icon} alt="Search" onClick={()=>search(inputRef.current.value)}/>
        </div>

        {weatherData?<>
            <img src={weatherData.icon} alt="" className='weather-icon'/>
        <p className='temperature'>{weatherData.temperature}°С</p>
        <p className='location'>{weatherData.location}</p>
        <div className="weather-data">

            <div className="col">
                <img src={Humidity} alt="" />
                <div>
                    <p>{weatherData.humidity} %</p>
                    <span>Humidity</span>
                </div>
            </div>

            <div className="col">
                <img src={Wind} alt="" />
                <div>
                    <p>{weatherData.windSpeed} km/h</p>
                    <span>Wind Speed</span>
                </div>
            </div>

        </div>
        </>:<></>}  

    </div>
  )
}

export default Weather
