import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { RouteReuseStrategy } from '@angular/router';
import { HttpClientModule } from '@angular/common/http';
import { IonicModule, IonicRouteStrategy } from '@ionic/angular';

import { environment } from '../environments/environment'; 

import { AppComponent } from './app.component';
import { AppRoutingModule } from './app-routing.module';

import { initializeApp, provideFirebaseApp } from '@angular/fire/app';
import { getFirestore, provideFirestore } from '@angular/fire/firestore';

@NgModule({
  declarations: [AppComponent],
  imports: [BrowserModule, IonicModule.forRoot(), AppRoutingModule, HttpClientModule,
           provideFirebaseApp(() => initializeApp(environment.firebaseConfig)),
           provideFirestore(() => getFirestore()),
           provideFirebaseApp(() => initializeApp({"projectId":"pokedex-dd742","appId":"1:908576069425:web:259f4f0fd29cba946e4210","storageBucket":"pokedex-dd742.appspot.com","apiKey":"AIzaSyAW7VVBao7UQ_G4tLwZ_dHMssPDpT_nE1Q","authDomain":"pokedex-dd742.firebaseapp.com","messagingSenderId":"908576069425","measurementId":"G-DJKKDEZ13F"})),],
  providers: [{ provide: RouteReuseStrategy, useClass: IonicRouteStrategy }],
  bootstrap: [AppComponent],
})
export class AppModule {}
