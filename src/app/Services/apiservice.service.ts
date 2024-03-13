import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Observable } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class APIServiceService {
  private apiUrl = 'https://pokeapi.co/api/v2/'; // URL base de la API

  constructor(private http: HttpClient) { }

  /**
   * Obtiene los datos de un Pokémon por su ID.
   * @param id El ID del Pokémon.
   * @returns Un Observable con los datos del Pokémon.
   */
  getPokemonID(id: number): Observable<any> {
    return this.http.get(this.apiUrl + "pokemon/" + id);
  }

  /**
   * Obtiene los datos de un Pokémon por su nombre.
   * @param name El nombre del Pokémon.
   * @returns Un Observable con los datos del Pokémon.
   */
  getPokemonName(name: string): Observable<any> {
    return this.http.get(this.apiUrl + "pokemon/" + name);
  }

  /**
   * Obtiene los datos de un ítem de Pokémon por su ID.
   * @param itemn El ID del ítem de Pokémon.
   * @returns Un Observable con los datos del ítem de Pokémon.
   */
  getPokemonitemn(itemn: number): Observable<any> {
    return this.http.get(`${this.apiUrl}item/${itemn}`);
  }

  /**
   * Obtiene los datos de un ítem de Pokémon por su nombre.
   * @param itemt El nombre del ítem de Pokémon.
   * @returns Un Observable con los datos del ítem de Pokémon.
   */

  getPokemonitemt(itemt: string): Observable<any> {
    return this.http.get(`${this.apiUrl}item/${itemt}`);
  }
  
}