<?xml version='1.0' encoding='utf-8'?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:NonHtml="http://www.progress.com/StylusStudio/NonHtml" exclude-result-prefixes="NonHtml">
	<xsl:output method="html"/>

	<xsl:template match="/"><head>
        <style type="text/css">
		body {
		font-family: "Trebuchet MS";
		}

		h1 {
			color: #ff0000;
		}

		table {
			border-style: none;
			border: 1px solid black;
			background-color: CCCCCC;
			empty-cells:show;
			border-collapse:collapse;
		}
		td {
			border-style:solid; 
			border-width:1px; 
			border-color:white;
		}
		</style>
      </head>
	<h1 align="center">Fiche client </h1>
	<h2>Civilité</h2>
	<p>
		<xsl:value-of select="Exportation/Personne/@Civilite"/><![CDATA[ ]]>
		<xsl:value-of select="Exportation/Personne/@Nom"/><![CDATA[ ]]>
		<xsl:value-of select="Exportation/Personne/@Prenom"/><![CDATA[ ]]>
		<xsl:choose>
			<xsl:when test="Exportation/Personne/@Beneficiaire='oui'">est un client</xsl:when>
			<xsl:otherwise>est un prospect</xsl:otherwise>
		</xsl:choose>
	</p>
	<p>
		<xsl:if test="Exportation/Personne/NomJeuneFille">Nom de jeune fille : 
			<xsl:value-of select="Exportation/Personne/NomJeuneFille"/>
		</xsl:if>
	</p>
	<p>Né le 
		<xsl:value-of select="Exportation/Personne/DateNaissance"/> à 
		<xsl:value-of select="Exportation/Personne/LieuNaissance"/>
	</p>
	<p>
		<table>
			<tbody>
				<tr>
					<td width="50%">
						<p align="center">
							<strong>Adresse personnelle</strong>
						</p>
					</td>
					<td width="50%">
						<p align="center">
							<strong>Adresse de gestion</strong>
						</p>
					</td>
				</tr>
				<tr>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/Adresse/Rue"/>
					</td>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/AdresseGestion/Rue"/>
					</td>
				</tr>
				<tr>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/Adresse/Complement"/>
					</td>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/AdresseGestion/Complement"/>
					</td>
				</tr>
				<tr>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/Adresse/CodePostal"/>
					</td>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/AdresseGestion/CodePostal"/>
					</td>
				</tr>
				<tr>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/Adresse/Ville"/>
					</td>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/AdresseGestion/Ville"/>
					</td>
				</tr>
				<tr>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/Telephone"/>
					</td>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/TelephonePro"/>
					</td>
				</tr>
				<tr>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/TelephonePortable"/>
					</td>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/Fax"/>
					</td>
				</tr>
				<tr>
					<td width="50%"/>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/Mail"/>
					</td>
				</tr>
				<tr>
					<td width="50%"/>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/LienEntreprise"/> est gérant 
						<xsl:value-of select="Exportation/Personne/Gerant"/>
					</td>
				</tr>
			</tbody>
		</table>
	</p>
	<h3>Conseillers</h3>
	<p>
		<table>
			<tbody>
				<tr>
					<td width="33%">
						<p align="center">
							<strong>Nom</strong>
						</p>
					</td>
					<td width="33%">
						<p align="center">
							<strong>Société</strong>
						</p>
					</td>
					<td width="33%">
						<p align="center">
							<strong>Type</strong>
						</p>
					</td>
				</tr>
				<xsl:for-each select="Exportation/Personne/Conseillers/Conseiller">
					<tr>
						<td width="33%">
							<xsl:value-of select="@Nom"/>
						</td>
						<td width="33%">
							<xsl:value-of select="@Societe"/>
						</td>
						<td width="33%">
							<xsl:choose>
								<xsl:when test="@Type='0'">Comptable</xsl:when>
								<xsl:when test="@Type='1'">Notaire</xsl:when>
								<xsl:when test="@Type='2'">Avocat</xsl:when>
							</xsl:choose>
						</td>
					</tr>
				</xsl:for-each>
			</tbody>
		</table>
	</p>
	<h2/>
	<h2>Revenus</h2>
	<p>
		<table>
			<tbody>
				<tr>
					<td width="25%">Salaire annuel</td>
					<td width="25%">
						<xsl:value-of select="Exportation/Personne/Revenus/SalaireAnnuel"/> € ( 
						<xsl:value-of select="Exportation/Personne/Revenus/TypeSalaire"/>) 
					</td>
					<td width="25%">Status professionnel</td>
					<td width="25%">
						<xsl:choose>
							<xsl:when test="Exportation/Personne/Revenus/StatusPro='0'">Salarié</xsl:when>
							<xsl:when test="Exportation/Personne/Revenus/StatusPro='1'">Salarié cadre</xsl:when>
							<xsl:when test="Exportation/Personne/Revenus/StatusPro='2'">ETAM</xsl:when>
							<xsl:when test="Exportation/Personne/Revenus/StatusPro='3'">Fonctionnaire</xsl:when>
							<xsl:when test="Exportation/Personne/Revenus/StatusPro='4'">Artisant</xsl:when>
							<xsl:when test="Exportation/Personne/Revenus/StatusPro='5'">Commercant</xsl:when>
							<xsl:when test="Exportation/Personne/Revenus/StatusPro='6'">Liberal</xsl:when>
							<xsl:when test="Exportation/Personne/Revenus/StatusPro='7'">Exploitant Agricole</xsl:when>
						</xsl:choose>
					</td>
				</tr>
				<tr>
					<td width="25%">BIC</td>
					<td width="25%">
						<xsl:value-of select="Exportation/Personne/Revenus/BIC"/>
					</td>
					<td width="25%">Mois du bilan</td>
					<td width="25%">
						<xsl:choose>
							<xsl:when test="Exportation/Personne/Revenus/MoisBilan='0'">Janvier</xsl:when>
							<xsl:when test="Exportation/Personne/Revenus/MoisBilan='1'">Février</xsl:when>
							<xsl:when test="Exportation/Personne/Revenus/MoisBilan='2'">Mars</xsl:when>
							<xsl:when test="Exportation/Personne/Revenus/MoisBilan='3'">Avril</xsl:when>
							<xsl:when test="Exportation/Personne/Revenus/MoisBilan='4'">Mai</xsl:when>
							<xsl:when test="Exportation/Personne/Revenus/MoisBilan='5'">Juin</xsl:when>
							<xsl:when test="Exportation/Personne/Revenus/MoisBilan='6'">Juillet</xsl:when>
							<xsl:when test="Exportation/Personne/Revenus/MoisBilan='7'">Août</xsl:when>
							<xsl:when test="Exportation/Personne/Revenus/MoisBilan='8'">Septembre</xsl:when>
							<xsl:when test="Exportation/Personne/Revenus/MoisBilan='9'">Octobre</xsl:when>
							<xsl:when test="Exportation/Personne/Revenus/MoisBilan='10'">Novembre</xsl:when>
							<xsl:when test="Exportation/Personne/Revenus/MoisBilan='11'">Décembre</xsl:when>
						</xsl:choose>
					</td>
				</tr>
				<tr>
					<td width="25%">BNC</td>
					<td width="25%">
						<xsl:value-of select="Exportation/Personne/Revenus/BNC"/>
					</td>
					<td width="25%">Employeur</td>
					<td width="25%">
						<xsl:value-of select="Exportation/Personne/Revenus/Employeur"/>
					</td>
				</tr>
				<tr>
					<td width="25%">Dividendes</td>
					<td width="25%">
						<xsl:value-of select="Exportation/Personne/Revenus/Dividendes"/>
					</td>
					<td width="25%">Fonction</td>
					<td width="25%">
						<xsl:value-of select="Exportation/Personne/Revenus/Fonction"/>
					</td>
				</tr>
				<tr>
					<td width="25%">Revenus fonciers</td>
					<td width="25%">
						<xsl:value-of select="Exportation/Personne/Revenus/RevenusFonciers"/>
					</td>
					<td width="25%"/>
					<td width="25%"/>
				</tr>
				<tr>
					<td width="25%">Autre revenus</td>
					<td width="25%">
						<xsl:value-of select="Exportation/Personne/Revenus/AutresRevenus"/>
					</td>
					<td width="25%"/>
					<td width="25%"/>
				</tr>
			</tbody>
		</table>
	</p>
	<h3>Fiscalité</h3>
	<p>
		<table>
			<tbody>
				<tr>
					<td width="50%">Montant de l'impôt</td>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/Fiscalite/Montant"/> € 
					</td>
				</tr>
				<tr>
					<td width="50%">Montant de l'ISF</td>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/Fiscalite/ISF"/>
					</td>
				</tr>
				<tr>
					<td width="50%">CGA/AGA</td>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/Fiscalite/CGA_VGA"/>
					</td>
				</tr>
				<tr>
					<td width="50%">Déductions</td>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/Fiscalite/Deductions"/> € 
					</td>
				</tr>
			</tbody>
		</table>
	</p>
	<h2>Epargne</h2>
	<p>Sensibilité au risque : 
		<xsl:value-of select="Exportation/Personne/Epargne/@Sensibilite"/>
	</p>
	<h3>Motivations</h3>
	<p>
		<table>
			<tbody>
				<tr>
					<td width="25%">
						<p align="center">
							<strong>Motivation 1ère</strong>
						</p>
					</td>
					<td width="25%">
						<p align="center">
							<strong>Motivation 2</strong>
						</p>
					</td>
					<td width="25%">
						<p align="center">
							<strong>Motivation 3</strong>
						</p>
					</td>
					<td width="25%">
						<p align="center">
							<strong>Motivation 4</strong>
						</p>
					</td>
				</tr>
				<tr>
					<td width="25%">
						<xsl:choose>
							<xsl:when test="Exportation/Personne/Epargne/Motivation/Motivation1='0'">Fiscalité</xsl:when>
							<xsl:when test="Exportation/Personne/Epargne/Motivation/Motivation1='1'">Disponibilite</xsl:when>
							<xsl:when test="Exportation/Personne/Epargne/Motivation/Motivation1='2'">Securite</xsl:when>
							<xsl:when test="Exportation/Personne/Epargne/Motivation/Motivation1='3'">Rentabilite</xsl:when>
						</xsl:choose>
					</td>
					<td width="25%">
						<xsl:choose>
							<xsl:when test="Exportation/Personne/Epargne/Motivation/Motivation2='0'">Fiscalité</xsl:when>
							<xsl:when test="Exportation/Personne/Epargne/Motivation/Motivation2='1'">Disponibilite</xsl:when>
							<xsl:when test="Exportation/Personne/Epargne/Motivation/Motivation2='2'">Securite</xsl:when>
							<xsl:when test="Exportation/Personne/Epargne/Motivation/Motivation2='3'">Rentabilite</xsl:when>
						</xsl:choose>
					</td>
					<td width="25%">
						<xsl:choose>
							<xsl:when test="Exportation/Personne/Epargne/Motivation/Motivation3='0'">Fiscalité</xsl:when>
							<xsl:when test="Exportation/Personne/Epargne/Motivation/Motivation3='1'">Disponibilite</xsl:when>
							<xsl:when test="Exportation/Personne/Epargne/Motivation/Motivation3='2'">Securite</xsl:when>
							<xsl:when test="Exportation/Personne/Epargne/Motivation/Motivation3='3'">Rentabilite</xsl:when>
						</xsl:choose>
					</td>
					<td width="25%">
						<xsl:choose>
							<xsl:when test="Exportation/Personne/Epargne/Motivation/Motivation4='0'">Fiscalité</xsl:when>
							<xsl:when test="Exportation/Personne/Epargne/Motivation/Motivation4='1'">Disponibilite</xsl:when>
							<xsl:when test="Exportation/Personne/Epargne/Motivation/Motivation4='2'">Securite</xsl:when>
							<xsl:when test="Exportation/Personne/Epargne/Motivation/Motivation4='3'">Rentabilite</xsl:when>
						</xsl:choose>
					</td>
				</tr>
			</tbody>
		</table>
	</p>
	<h3>Epargne</h3>
	<p>
		<table>
			<tbody>
				<tr>
					<td width="14%">
						<p align="center">
							<strong>Type</strong>
						</p>
					</td>
					<td width="14%">
						<p align="center">
							<strong>Date d'effet</strong>
						</p>
					</td>
					<td width="14%">
						<p align="center">
							<strong>Inv annuel</strong>
						</p>
					</td>
					<td width="14%">
						<p align="center">
							<strong>Montant €</strong>
						</p>
					</td>
					<td width="14%">
						<p align="center">
							<strong>Date</strong>
						</p>
					</td>
					<td width="14%">
						<p align="center">
							<strong>Contrat</strong>
						</p>
					</td>
					<td width="14%">
						<p align="center">
							<strong>Compagnie</strong>
						</p>
					</td>
				</tr>
				<xsl:for-each select="Exportation/Personne/Epargne/Retraites/Retraite">
					<tr>
						<td width="14%">
							<xsl:value-of select="@type"/>
							<xsl:choose>
								<xsl:when test="@type='0'">Loi madelin</xsl:when>
								<xsl:when test="@type='1'">Art 83</xsl:when>
								<xsl:when test="@type='2'">Art 82</xsl:when>
								<xsl:when test="@type='3'">Perp</xsl:when>
								<xsl:when test="@type='4'">Perco</xsl:when>
								<xsl:when test="@type='5'">Art 39</xsl:when>
								<xsl:when test="@type='6'">IFC</xsl:when>
								<xsl:when test="@type='7'">Autre retraite</xsl:when>
							</xsl:choose>
						</td>
						<td width="14%">
							<xsl:value-of select="DateEffet"/>
						</td>
						<td width="14%">
							<xsl:value-of select="InvAnnuel"/>
						</td>
						<td width="14%">
							<xsl:value-of select="MontantEpargne"/>
						</td>
						<td width="14%">
							<xsl:value-of select="DateEpargne"/>
						</td>
						<td width="14%">
							<xsl:value-of select="Contrat"/>
						</td>
						<td width="14%">
							<xsl:value-of select="Compagnie"/>
						</td>
					</tr>
				</xsl:for-each>
			</tbody>
		</table>
	</p>
	<h3>Assurance Vie</h3>
	<p>
		<table>
			<tbody>
				<tr>
					<td width="9%">
						<p align="center">
							<strong>Contrat</strong>
						</p>
					</td>
					<td width="9%">
						<p align="center">
							<strong>Compagnie</strong>
						</p>
					</td>
					<td width="9%">
						<p align="center">
							<strong>Date d'effet</strong>
						</p>
					</td>
					<td width="9%">
						<p align="center">
							<strong>Inv Annuel</strong>
						</p>
					</td>
					<td width="9%">
						<p align="center">
							<strong>Terme</strong>
						</p>
					</td>
					<td width="9%">
						<p align="center">
							<strong>Capital €</strong>
						</p>
					</td>
					<td width="9%">
						<p align="center">
							<strong>Date capital</strong>
						</p>
					</td>
					<td width="9%">
						<p align="center">
							<strong>DSK</strong>
						</p>
					</td>
					<td width="9%">
						<p align="center">
							<strong>PEP</strong>
						</p>
					</td>
					<td width="9%">
						<p align="center">
							<strong>MS</strong>
						</p>
					</td>
					<td width="9%">
						<p align="center">
							<strong>FD</strong>
						</p>
					</td>
				</tr>
				<xsl:for-each select="Exportation/Personne/Epargne/AssuranceVies/AssuranceVie">
					<tr>
						<td width="9%">
							<xsl:value-of select="Contrat"/>
						</td>
						<td width="9%">
							<xsl:value-of select="Compagnie"/>
						</td>
						<td width="9%">
							<xsl:value-of select="DateEffet"/>
						</td>
						<td width="9%">
							<xsl:value-of select="InvAnnuel"/>
						</td>
						<td width="9%">
							<xsl:value-of select="Terme"/>
						</td>
						<td width="9%">
							<xsl:value-of select="Capital"/>
						</td>
						<td width="9%">
							<xsl:value-of select="DateCapital"/>
						</td>
						<td width="9%">
							<xsl:value-of select="DSK"/>
						</td>
						<td width="9%">
							<xsl:value-of select="PEP"/>
						</td>
						<td width="9%">
							<xsl:value-of select="MS"/>
						</td>
						<td width="9%">
							<xsl:value-of select="FD"/>
						</td>
					</tr>
				</xsl:for-each>
			</tbody>
		</table>
	</p>
	<h3>Comptes</h3>
	<p>
		<table>
			<tbody>
				<tr>
					<td width="11%">
						<p align="center">
							<strong>Type</strong>
						</p>
					</td>
					<td width="11%">
						<p align="center">
							<strong>Compagnie</strong>
						</p>
					</td>
					<td width="11%">
						<p align="center">
							<strong>Date</strong>
						</p>
					</td>
					<td width="11%">
						<p align="center">
							<strong>Inv Annuel</strong>
						</p>
					</td>
					<td width="11%">
						<p align="center">
							<strong>Terme</strong>
						</p>
					</td>
					<td width="11%">
						<p align="center">
							<strong>Capital</strong>
						</p>
					</td>
					<td width="11%">
						<p align="center">
							<strong>Date Capital</strong>
						</p>
					</td>
					<td width="11%">
						<p align="center">
							<strong>Rendement</strong>
						</p>
					</td>
					<td width="11%">
						<p align="center">
							<strong>Notes</strong>
						</p>
					</td>
				</tr>
				<xsl:for-each select="Exportation/Personne/Epargne/Comptes/Compte">
					<tr>
						<td width="11%">
							<xsl:value-of select="@type"/>
						</td>
						<td width="11%">
							<xsl:value-of select="Compagnie"/>
						</td>
						<td width="11%">
							<xsl:value-of select="DateEffet"/>
						</td>
						<td width="11%">
							<xsl:value-of select="InvAnnuel"/>
						</td>
						<td width="11%">
							<xsl:value-of select="Terme"/>
						</td>
						<td width="11%">
							<xsl:value-of select="Capital"/>
						</td>
						<td width="11%">
							<xsl:value-of select="DateCapital"/>
						</td>
						<td width="11%">
							<xsl:value-of select="Rendement"/>
						</td>
						<td width="11%">
							<xsl:value-of select="Notes"/>
						</td>
					</tr>
				</xsl:for-each>
			</tbody>
		</table>
	</p>
	<h3>Revenus</h3>
	<p>
		<table>
			<tbody>
				<tr>
					<td width="50%">
						<strong>Designation</strong>
					</td>
					<td width="50%">
						<strong>Montant €</strong>
					</td>
				</tr>
				<xsl:for-each select="Exportation/Personne/Epargne/Revenus/Revenu">
					<tr>
						<td width="50%">
							<xsl:value-of select="@Designation"/>
						</td>
						<td width="50%">
							<xsl:value-of select="@Montant"/>
						</td>
					</tr>
				</xsl:for-each>
			</tbody>
		</table>
	</p>
	<h3>Charges</h3>
	<p>
		<table>
			<tbody>
				<tr>
					<td width="50%">
						<strong>Designation</strong>
					</td>
					<td width="50%">
						<strong>Montant €</strong>
					</td>
				</tr>
				<xsl:for-each select="Exportation/Personne/Epargne/Charges/Charge">
					<tr>
						<td width="50%">
							<xsl:value-of select="@Designation"/>
						</td>
						<td width="50%">
							<xsl:value-of select="@Montant"/>
						</td>
					</tr>
				</xsl:for-each>
			</tbody>
		</table>
	</p>
	<h2>Prevoyance</h2>
	<p>
		<table>
			<tbody>
				<tr>
					<td width="50%">Niveau de garanties : 
						<xsl:value-of select="Exportation/Personne/Prevoyance/NiveauGaranties"/>&#160; 
					</td>
					<td width="50%">Compagnie : 
						<xsl:value-of select="Exportation/Personne/Prevoyance/Compagnie"/>
					</td>
				</tr>
				<tr>
					<td width="50%">Indice de satisfaction : 
						<xsl:value-of select="Exportation/Personne/Prevoyance/IndiceSatisfaction"/>&#160; 
					</td>
					<td width="50%">Beneficiaires : 
						<xsl:value-of select="Exportation/Personne/Prevoyance/Beneficiaires"/>
					</td>
				</tr>
				<tr>
					<td width="50%">Cotisation annuelle: 
						<xsl:value-of select="Exportation/Personne/Prevoyance/CotisationAnnuelle"/>
					</td>
					<td width="50%">Viager : 
						<xsl:value-of select="Exportation/Personne/Prevoyance/Viager/@EnViager"/> ( 
						<xsl:value-of select="Exportation/Personne/Prevoyance/Viager/@type"/>) 
					</td>
				</tr>
				<tr>
					<td width="50%">Fiscalité : 
						<xsl:value-of select="Exportation/Personne/Prevoyance/Fiscalite"/>
					</td>
					<td width="50%">Date effet : 
						<xsl:value-of select="Exportation/Personne/Prevoyance/DateEffet"/>
					</td>
				</tr>
				<tr>
					<td width="50%">Contrat: 
						<xsl:value-of select="Exportation/Personne/Prevoyance/Contrat"/>
					</td>
					<td width="50%">Source : 
						<xsl:value-of select="Exportation/Personne/Prevoyance/Source"/>
					</td>
				</tr>
			</tbody>
		</table>
	</p>
	<p>Notes</p>
	<p>
		<table>
			<tbody>
				<tr>
					<td>
						<xsl:value-of select="Exportation/Personne/Prevoyance/Notes"/>
					</td>
				</tr>
			</tbody>
		</table>
	</p>
	<h3>Couverture d'emprunt</h3>
	<p>
		<table>
			<tbody>
				<tr>
					<td width="14%">
						<p align="center">
							<strong>Banque</strong>
						</p>
					</td>
					<td width="14%">
						<p align="center">
							<strong>Debut</strong>
						</p>
					</td>
					<td width="14%">
						<p align="center">
							<strong>Franchise</strong>
						</p>
					</td>
					<td width="14%">
						<p align="center">
							<strong>Montant €</strong>
						</p>
					</td>
					<td width="14%">
						<p align="center">
							<strong>Taux Moyen</strong>
						</p>
					</td>
					<td width="14%">
						<p align="center">
							<strong>Terme</strong>
						</p>
					</td>
					<td width="14%">
						<p align="center">
							<strong>Type d'emprunt</strong>
						</p>
					</td>
				</tr>
				<xsl:for-each select="Exportation/Personne/Prevoyance/ListeCouvertureEmprunt/Emprunt">
					<tr>
						<td width="14%">
							<xsl:value-of select="@Banque"/>
						</td>
						<td width="14%">
							<xsl:value-of select="@Debut"/>
						</td>
						<td width="14%">
							<xsl:value-of select="@Franchise"/>
						</td>
						<td width="14%">
							<xsl:value-of select="@Montant"/><![CDATA[ ]]>
						</td>
						<td width="14%">
							<xsl:value-of select="@TauxMoyen"/>
						</td>
						<td width="14%">
							<xsl:value-of select="@Terme"/>
						</td>
						<td width="14%">
							<xsl:value-of select="@TypeEmprunt"/>
						</td>
					</tr>
				</xsl:for-each>
			</tbody>
		</table>
	</p>
	<h3>Arret maladie</h3>
	<p>
		<table>
			<tbody>
				<tr>
					<td width="50%">Accord associés : 
						<xsl:value-of select="Exportation/Personne/Prevoyance/ArretMaladie/AccordAssocies"/>
					</td>
					<td width="50%">Date d'effet : 
						<xsl:value-of select="Exportation/Personne/Prevoyance/ArretMaladie/DateEffet"/>
					</td>
				</tr>
				<tr>
					<td width="50%">Date de mise à jour : 
						<xsl:value-of select="Exportation/Personne/Prevoyance/ArretMaladie/DateMiseAJour"/>
					</td>
					<td width="50%">Compagnie : 
						<xsl:value-of select="Exportation/Personne/Prevoyance/ArretMaladie/Compagnie"/>&#160; 
					</td>
				</tr>
				<tr>
					<td width="50%">Contrat : 
						<xsl:value-of select="Exportation/Personne/Prevoyance/ArretMaladie/Contrat"/>
					</td>
					<td width="50%">Fiscalité : 
						<xsl:value-of select="Exportation/Personne/Prevoyance/ArretMaladie/Fiscalite"/>
					</td>
				</tr>
				<tr>
					<td width="50%">Duree accord : 
						<xsl:value-of select="Exportation/Personne/Prevoyance/ArretMaladie/Fiscalite"/>
					</td>
					<td width="50%">Franchise accident : 
						<xsl:value-of select="Exportation/Personne/Prevoyance/ArretMaladie/FranchiseAccident"/>
					</td>
				</tr>
				<tr>
					<td width="50%">Franchise hopital : 
						<xsl:value-of select="Exportation/Personne/Prevoyance/ArretMaladie/FranchiseHopital"/>
					</td>
					<td width="50%">Franchise maladie : 
						<xsl:value-of select="Exportation/Personne/Prevoyance/ArretMaladie/FranchiseMaladie"/>
					</td>
				</tr>
			</tbody>
		</table>
	</p>
	<h3>Arrêts de travail</h3>
	<p>
		<table>
			<tbody>
				<tr>
					<td width="33%">
						<strong>Duree</strong>
					</td>
					<td width="33%">
						<strong>Franchise €</strong>
					</td>
					<td width="33%">
						<strong>Montant €</strong>
					</td>
				</tr>
				<xsl:for-each select="Exportation/Personne/Prevoyance/ArretMaladie/ListeArretTravail/Arret">
					<tr>
						<td width="33%">
							<xsl:value-of select="@Duree"/>
						</td>
						<td width="33%">
							<xsl:value-of select="@Franchise"/>
						</td>
						<td width="33%">
							<xsl:value-of select="@Montant"/>
						</td>
					</tr>
				</xsl:for-each>
			</tbody>
		</table>
	</p>
	<h3/>
	<h3>Frais généraux</h3>
	<p>
		<table>
			<tbody>
				<tr>
					<td width="25%">
						<p align="center">
							<strong>Compagnie</strong>
						</p>
					</td>
					<td width="25%">
						<p align="center">
							<strong>Contrat</strong>
						</p>
					</td>
					<td width="25%">
						<p align="center">
							<strong>Couverture mensuelle</strong>
						</p>
					</td>
					<td width="25%">
						<p align="center">
							<strong>Franchise €</strong>
						</p>
					</td>
				</tr>
				<tr>
					<td width="25%">
						<xsl:value-of select="Exportation/Personne/Prevoyance/FraisGeneraux/Compagnie"/>
					</td>
					<td width="25%">
						<xsl:value-of select="Exportation/Personne/Prevoyance/FraisGeneraux/Contrat"/>
					</td>
					<td width="25%">
						<xsl:value-of select="Exportation/Personne/Prevoyance/FraisGeneraux/CouvertureMensuelle"/>
					</td>
					<td width="25%">
						<xsl:value-of select="Exportation/Personne/Prevoyance/FraisGeneraux/Franchise"/>
					</td>
				</tr>
			</tbody>
		</table>
	</p>
	<h3>Invalidite</h3>
	<p>
		<table>
			<tbody>
				<tr>
					<td width="10%">
						<p align="center">
							<strong>Professionnel</strong>
						</p>
					</td>
					<td width="10%">
						<p align="center">
							<strong>Date d'effet</strong>
						</p>
					</td>
					<td width="10%">
						<p align="center">
							<strong>Date Maj</strong>
						</p>
					</td>
					<td width="10%">
						<p align="center">
							<strong>Compagnie</strong>
						</p>
					</td>
					<td width="10%">
						<p align="center">
							<strong>Fiscalité</strong>
						</p>
					</td>
					<td width="10%">
						<p align="center">
							<strong>Notes</strong>
						</p>
					</td>
					<td width="10%">
						<p align="center">
							<strong>Capitaux Inv. 60%</strong>
						</p>
					</td>
					<td width="10%">
						<p align="center">
							<strong>Rente inv 100%</strong>
						</p>
					</td>
					<td width="10%">
						<p align="center">
							<strong>Rente inv. 66%</strong>
						</p>
					</td>
					<td width="10%">
						<p align="center">
							<strong>Rente inv.33%</strong>
						</p>
					</td>
				</tr>
				<tr>
					<td width="10%">
						<xsl:value-of select="Exportation/Personne/Prevoyance/Invalidite/@Professionnel"/>
					</td>
					<td width="10%">
						<xsl:value-of select="Exportation/Personne/Prevoyance/Invalidite/DateEffet"/>
					</td>
					<td width="10%">
						<xsl:value-of select="Exportation/Personne/Prevoyance/Invalidite/DateMiseAJour"/>
					</td>
					<td width="10%">
						<xsl:value-of select="Exportation/Personne/Prevoyance/Invalidite/Compagnie"/>
					</td>
					<td width="10%">
						<xsl:value-of select="Exportation/Personne/Prevoyance/Invalidite/Fiscalite"/>
					</td>
					<td width="10%">
						<xsl:value-of select="Exportation/Personne/Prevoyance/Invalidite/Notes"/>
					</td>
					<td width="10%">
						<xsl:value-of select="Exportation/Personne/Prevoyance/Invalidite/CapitauxInvalidite60"/>
					</td>
					<td width="10%">
						<xsl:value-of select="Exportation/Personne/Prevoyance/Invalidite/RenteInvalidite100"/>
					</td>
					<td width="10%">
						<xsl:value-of select="Exportation/Personne/Prevoyance/Invalidite/RenteInvalidite66"/>
					</td>
					<td width="10%">
						<xsl:value-of select="Exportation/Personne/Prevoyance/Invalidite/RenteInvalidite33"/>
					</td>
				</tr>
			</tbody>
		</table>
	</p>
	<h3>Deces</h3>
	<p>
		<table>
			<tbody>
				<tr>
					<td width="50%">Date effet conjoint</td>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/Prevoyance/Deces/DateEffetConjoint"/>
					</td>
				</tr>
				<tr>
					<td width="50%">Date effet education</td>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/Prevoyance/Deces/DateEffetEducation"/>
					</td>
				</tr>
				<tr>
					<td width="50%">Compagnie conjoint</td>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/Prevoyance/Deces/CompagnieConjoint"/>
					</td>
				</tr>
				<tr>
					<td width="50%">Fiscalité conjoint</td>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/Prevoyance/Deces/FiscaliteConjoint"/>
					</td>
				</tr>
				<tr>
					<td width="50%">Fiscalité éducation</td>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/Prevoyance/Deces/FiscaliteEducation"/>
					</td>
				</tr>
				<tr>
					<td width="50%">Durée rente conjoint</td>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/Prevoyance/Deces/DureeRenteConjoint"/>
					</td>
				</tr>
				<tr>
					<td width="50%">Compagnie éducation</td>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/Prevoyance/Deces/CompagnieEducation"/>
					</td>
				</tr>
				<tr>
					<td width="50%">Notes</td>
					<td width="50%">
						<xsl:value-of select="Exportation/Personne/Prevoyance/Deces/Notes"/>
					</td>
				</tr>
			</tbody>
		</table>
	</p>
	<h3>Liste des garanties décès</h3>
	<p>
		<table>
			<tbody>
				<tr>
					<td width="11%">
						<p align="center">
							<strong>Accident</strong>
						</p>
					</td>
					<td width="11%">
						<p align="center">
							<strong>Autre</strong>
						</p>
					</td>
					<td width="11%">
						<p align="center">
							<strong>Bénéficiaire</strong>
						</p>
					</td>
					<td width="11%">
						<p align="center">
							<strong>Capitaux €</strong>
						</p>
					</td>
					<td width="11%">
						<p align="center">
							<strong>Compagnie</strong>
						</p>
					</td>
					<td width="11%">
						<p align="center">
							<strong>Date effet</strong>
						</p>
					</td>
					<td width="11%">
						<p align="center">
							<strong>Durée</strong>
						</p>
					</td>
					<td width="11%">
						<p align="center">
							<strong>Fiscalité</strong>
						</p>
					</td>
					<td width="11%">
						<p align="center">
							<strong>Maladie</strong>
						</p>
					</td>
				</tr>
				<xsl:for-each select="Exportation/Personne/Prevoyance/Deces/ListeGarantiesDeces/GarantieDeces">
					<tr>
						<td width="11%">
							<xsl:value-of select="@Accident"/>
						</td>
						<td width="11%">
							<xsl:value-of select="@Autre"/>
						</td>
						<td width="11%">
							<xsl:value-of select="@Beneficiaire"/>
						</td>
						<td width="11%">
							<xsl:value-of select="@Capitaux"/>
						</td>
						<td width="11%">
							<xsl:value-of select="@Compagnie"/>
						</td>
						<td width="11%">
							<xsl:value-of select="@DateEffet"/>
						</td>
						<td width="11%">
							<xsl:value-of select="@Duree"/>
						</td>
						<td width="11%">
							<xsl:value-of select="@Fiscalite"/>
						</td>
						<td width="11%">
							<xsl:value-of select="@Maladie"/>
						</td>
					</tr>
				</xsl:for-each>
			</tbody>
		</table>
	</p>
	<h3>Liste rente éducation</h3>
	<p>
		<table>
			<tbody>
				<tr>
					<td width="25%">
						<p align="center">
							<strong>Date de début</strong>
						</p>
					</td>
					<td width="25%">
						<p align="center">
							<strong>Date de fin</strong>
						</p>
					</td>
					<td width="25%">
						<p align="center">
							<strong>Montant €</strong>
						</p>
					</td>
					<td width="25%">
						<p align="center">
							<strong>Pourcentage</strong>
						</p>
					</td>
				</tr>
				<xsl:for-each select="Exportation/Personne/Prevoyance/Deces/ListeRenteEducation/Rente">
					<tr>
						<td width="25%">
							<xsl:value-of select="@Debut"/>
						</td>
						<td width="25%">
							<xsl:value-of select="@Fin"/>
						</td>
						<td width="25%">
							<xsl:value-of select="@Montant"/>
						</td>
						<td width="25%">
							<xsl:value-of select="@Pourcentage"/>
						</td>
					</tr>
				</xsl:for-each>
			</tbody>
		</table>
	</p>
	<h2>Carrière</h2>
	<p>Age de retraite souhaité : 
		<xsl:value-of select="Exportation/Personne/Carriere/AgeRetraite"/>
	</p>
	<p>
		<strong>Liste des emplois occupés</strong>
	</p>
	<p>
		<table>
			<tbody>
				<tr>
					<td width="16%">
						<p align="center">
							<strong>Date entrée</strong>
						</p>
					</td>
					<td width="16%">
						<p align="center">
							<strong>Date de fin</strong>
						</p>
					</td>
					<td width="16%">
						<p align="center">
							<strong>Points RCO</strong>
						</p>
					</td>
					<td width="16%">
						<p align="center">
							<strong>Revenus €</strong>
						</p>
					</td>
					<td width="16%">
						<p align="center">
							<strong>Statut</strong>
						</p>
					</td>
					<td width="16%">
						<p align="center">
							<strong>Note</strong>
						</p>
					</td>
				</tr>
				<xsl:for-each select="Exportation/Personne/Carriere/Emplois/Emploi">
					<tr>
						<td width="16%">
							<xsl:value-of select="@DateEntree"/>
						</td>
						<td width="16%">
							<xsl:value-of select="@DateFin"/>
						</td>
						<td width="16%">
							<xsl:value-of select="@PointsRCO"/>
						</td>
						<td width="16%">
							<xsl:value-of select="@Revenus"/>
						</td>
						<td width="16%">
							<xsl:value-of select="@Statut"/>
						</td>
						<td width="16%">
							<xsl:value-of select="Note"/>
						</td>
					</tr>
				</xsl:for-each>
			</tbody>
		</table>
	</p>
	<h3>Notes sur le client</h3>
	<p>
		<table>
			<tbody>
				<tr>
					<td>
						<xsl:value-of select="Exportation/Personne/Notes"/>
					</td>
				</tr>
			</tbody>
		</table>
	</p>
	<h3>Besoins du client</h3>
	<p>
		<u>
			<table>
				<tbody>
					<tr>
						<td width="50%">Prévoyance</td>
						<td width="50%">
							<xsl:value-of select="Exportation/Personne/Besoins/Prevoyance"/>
						</td>
					</tr>
					<tr>
						<td width="50%">Retraite</td>
						<td width="50%">
							<xsl:value-of select="Exportation/Personne/Besoins/Retraite"/>
						</td>
					</tr>
					<tr>
						<td width="50%">Epargne</td>
						<td width="50%">
							<xsl:value-of select="Exportation/Personne/Besoins/Epargne"/>
						</td>
					</tr>
					<tr>
						<td width="50%">Patrimoine</td>
						<td width="50%">
							<xsl:value-of select="Exportation/Personne/Besoins/Patrimoine"/>
						</td>
					</tr>
					<tr>
						<td width="50%">Santé</td>
						<td width="50%">
							<xsl:value-of select="Exportation/Personne/Besoins/Sante"/>
						</td>
					</tr>
				</tbody>
			</table>
		</u>
	</p>
	<p>&#160;</p>
	<p>&#160;</p>
</xsl:template>
</xsl:stylesheet><!-- Stylus Studio meta-information - (c) 2004-2006. Progress Software Corporation. All rights reserved.
<metaInformation>
<scenarios ><scenario default="yes" name="Scenario1" userelativepaths="yes" externalpreview="yes" url="file:///c:/Documents and Settings/Propriétaire/Bureau/export.xml" htmlbaseurl="" outputurl="file:///c:/Documents and Settings/Propriétaire/Bureau/toto.xml" processortype="internal" useresolver="yes" profilemode="0" profiledepth="" profilelength="" urlprofilexml="" commandline="" additionalpath="" additionalclasspath="" postprocessortype="none" postprocesscommandline="" postprocessadditionalpath="" postprocessgeneratedext="" validateoutput="yes" validator="internal" customvalidator="" ><validatorSchema value="personnes.xsd"/></scenario></scenarios><MapperMetaTag><MapperInfo srcSchemaPathIsRelative="yes" srcSchemaInterpretAsXML="no" destSchemaPath="" destSchemaRoot="" destSchemaPathIsRelative="yes" destSchemaInterpretAsXML="no" ><SourceSchema srcSchemaPath="personnes.xml" srcSchemaRoot="ListPersonnes" AssociatedInstance="" loaderFunction="document" loaderFunctionUsesURI="no"/></MapperInfo><MapperBlockPosition><template match="/"><block path="p[1]/xsl:value&#x2D;of" x="253" y="144"/><block path="p[1]/xsl:value&#x2D;of[1]" x="293" y="144"/><block path="p[1]/xsl:value&#x2D;of[2]" x="213" y="144"/><block path="p[1]/xsl:choose" x="103" y="114"/><block path="p[1]/xsl:choose/=[0]" x="57" y="108"/><block path="" x="162" y="144"/><block path="p[1]/xsl:if" x="84" y="192"/><block path="p[1]/xsl:if/xsl:value&#x2D;of" x="293" y="104"/><block path="p[1]/xsl:value&#x2D;of[3]" x="173" y="104"/><block path="p[1]/xsl:value&#x2D;of[4]" x="53" y="104"/><block path="p[2]/table/tbody/tr[1]/td/xsl:value&#x2D;of" x="253" y="141"/><block path="p[2]/table/tbody/tr[1]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[2]/table/tbody/tr[2]/td/xsl:value&#x2D;of" x="253" y="141"/><block path="p[2]/table/tbody/tr[2]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[2]/table/tbody/tr[3]/td/xsl:value&#x2D;of" x="253" y="141"/><block path="p[2]/table/tbody/tr[3]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[2]/table/tbody/tr[4]/td/xsl:value&#x2D;of" x="253" y="141"/><block path="p[2]/table/tbody/tr[4]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[2]/table/tbody/tr[5]/td/xsl:value&#x2D;of" x="253" y="141"/><block path="p[2]/table/tbody/tr[5]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[2]/table/tbody/tr[6]/td/xsl:value&#x2D;of" x="253" y="141"/><block path="p[2]/table/tbody/tr[6]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[2]/table/tbody/tr[7]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[2]/table/tbody/tr[8]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[2]/table/tbody/tr[8]/td[1]/xsl:value&#x2D;of[1]" x="253" y="141"/><block path="p[3]/xsl:for&#x2D;each" x="223" y="111"/><block path="p[3]/xsl:for&#x2D;each/xsl:value&#x2D;of" x="13" y="101"/><block path="p[3]/xsl:for&#x2D;each/xsl:value&#x2D;of[1]" x="293" y="61"/><block path="p[3]/xsl:for&#x2D;each/xsl:value&#x2D;of[2]" x="173" y="61"/><block path="p[4]/table/tbody/tr/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[4]/table/tbody/tr/td[1]/xsl:value&#x2D;of[1]" x="253" y="141"/><block path="p[4]/table/tbody/tr/td[3]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[4]/table/tbody/tr[1]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[4]/table/tbody/tr[1]/td[3]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[4]/table/tbody/tr[2]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[4]/table/tbody/tr[2]/td[3]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[4]/table/tbody/tr[3]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[4]/table/tbody/tr[3]/td[3]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[4]/table/tbody/tr[4]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[4]/table/tbody/tr[5]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[5]/table/tbody/tr/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[5]/table/tbody/tr[1]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[5]/table/tbody/tr[2]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[5]/table/tbody/tr[3]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[6]/xsl:value&#x2D;of" x="133" y="61"/><block path="p[8]/table/tbody/tr/td/xsl:value&#x2D;of" x="253" y="141"/><block path="p[8]/table/tbody/tr/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[8]/table/tbody/tr/td[2]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[8]/table/tbody/tr/td[3]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[9]/table/tbody/xsl:for&#x2D;each" x="93" y="221"/><block path="p[9]/table/tbody/xsl:for&#x2D;each/tr/td/xsl:value&#x2D;of" x="253" y="141"/><block path="p[9]/table/tbody/xsl:for&#x2D;each/tr/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[9]/table/tbody/xsl:for&#x2D;each/tr/td[2]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[9]/table/tbody/xsl:for&#x2D;each/tr/td[3]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[9]/table/tbody/xsl:for&#x2D;each/tr/td[4]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[9]/table/tbody/xsl:for&#x2D;each/tr/td[5]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[9]/table/tbody/xsl:for&#x2D;each/tr/td[6]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[11]/table/tbody/xsl:for&#x2D;each" x="53" y="221"/><block path="p[11]/table/tbody/xsl:for&#x2D;each/tr/td/xsl:value&#x2D;of" x="253" y="141"/><block path="p[11]/table/tbody/xsl:for&#x2D;each/tr/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[11]/table/tbody/xsl:for&#x2D;each/tr/td[2]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[11]/table/tbody/xsl:for&#x2D;each/tr/td[3]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[11]/table/tbody/xsl:for&#x2D;each/tr/td[4]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[11]/table/tbody/xsl:for&#x2D;each/tr/td[5]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[11]/table/tbody/xsl:for&#x2D;each/tr/td[6]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[11]/table/tbody/xsl:for&#x2D;each/tr/td[7]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[11]/table/tbody/xsl:for&#x2D;each/tr/td[8]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[12]/table/tbody/xsl:for&#x2D;each" x="13" y="221"/><block path="p[12]/table/tbody/xsl:for&#x2D;each/tr/td/xsl:value&#x2D;of" x="253" y="141"/><block path="p[12]/table/tbody/xsl:for&#x2D;each/tr/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[13]/table/tbody/xsl:for&#x2D;each" x="253" y="141"/><block path="p[13]/table/tbody/xsl:for&#x2D;each/tr/td/xsl:value&#x2D;of" x="253" y="141"/><block path="p[13]/table/tbody/xsl:for&#x2D;each/tr/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[14]/xsl:value&#x2D;of" x="93" y="61"/><block path="p[14]/xsl:value&#x2D;of[1]" x="53" y="61"/><block path="p[14]/xsl:value&#x2D;of[2]" x="13" y="61"/><block path="p[15]/xsl:value&#x2D;of" x="253" y="21"/><block path="p[15]/xsl:value&#x2D;of[1]" x="293" y="21"/><block path="p[15]/xsl:value&#x2D;of[2]" x="213" y="21"/><block path="p[15]/xsl:value&#x2D;of[3]" x="173" y="21"/><block path="p[16]/xsl:value&#x2D;of" x="133" y="21"/><block path="p[17]/xsl:value&#x2D;of" x="93" y="21"/><block path="p[17]/xsl:value&#x2D;of[1]" x="53" y="21"/><block path="p[17]/xsl:value&#x2D;of[2]" x="13" y="21"/><block path="p[17]/xsl:value&#x2D;of[3]" x="253" y="181"/><block path="p[18]/table/tbody/xsl:for&#x2D;each" x="253" y="141"/><block path="p[18]/table/tbody/xsl:for&#x2D;each/tr/td/xsl:value&#x2D;of" x="253" y="141"/><block path="p[18]/table/tbody/xsl:for&#x2D;each/tr/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[18]/table/tbody/xsl:for&#x2D;each/tr/td[2]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[18]/table/tbody/xsl:for&#x2D;each/tr/td[3]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[18]/table/tbody/xsl:for&#x2D;each/tr/td[4]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[18]/table/tbody/xsl:for&#x2D;each/tr/td[5]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[18]/table/tbody/xsl:for&#x2D;each/tr/td[6]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[19]/xsl:value&#x2D;of" x="293" y="181"/><block path="p[19]/xsl:value&#x2D;of[1]" x="213" y="181"/><block path="p[19]/xsl:value&#x2D;of[2]" x="173" y="181"/><block path="p[20]/xsl:value&#x2D;of" x="133" y="181"/><block path="p[20]/xsl:value&#x2D;of[1]" x="93" y="181"/><block path="p[20]/xsl:value&#x2D;of[2]" x="53" y="181"/><block path="p[20]/xsl:value&#x2D;of[3]" x="13" y="181"/><block path="p[21]/xsl:value&#x2D;of" x="253" y="221"/><block path="p[21]/xsl:value&#x2D;of[1]" x="293" y="221"/><block path="p[21]/xsl:value&#x2D;of[2]" x="213" y="221"/><block path="p[23]/table/tbody/xsl:for&#x2D;each" x="253" y="141"/><block path="p[23]/table/tbody/xsl:for&#x2D;each/tr/td/xsl:value&#x2D;of" x="253" y="141"/><block path="p[23]/table/tbody/xsl:for&#x2D;each/tr/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[23]/table/tbody/xsl:for&#x2D;each/tr/td[2]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[24]/table/tbody/tr[1]/td/xsl:value&#x2D;of" x="253" y="141"/><block path="p[24]/table/tbody/tr[1]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[24]/table/tbody/tr[1]/td[2]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[24]/table/tbody/tr[1]/td[3]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[25]/table/tbody/tr[1]/td/xsl:value&#x2D;of" x="253" y="141"/><block path="p[25]/table/tbody/tr[1]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[25]/table/tbody/tr[1]/td[2]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[25]/table/tbody/tr[1]/td[3]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[25]/table/tbody/tr[1]/td[4]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[25]/table/tbody/tr[1]/td[5]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[25]/table/tbody/tr[1]/td[6]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[25]/table/tbody/tr[1]/td[7]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[25]/table/tbody/tr[1]/td[8]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[25]/table/tbody/tr[1]/td[9]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[26]/table/tbody/tr/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[26]/table/tbody/tr[1]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[26]/table/tbody/tr[2]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[26]/table/tbody/tr[3]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[26]/table/tbody/tr[4]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[26]/table/tbody/tr[5]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[26]/table/tbody/tr[6]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[26]/table/tbody/tr[7]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[27]/table/tbody/xsl:for&#x2D;each" x="253" y="141"/><block path="p[27]/table/tbody/xsl:for&#x2D;each/tr/td/xsl:value&#x2D;of" x="253" y="141"/><block path="p[27]/table/tbody/xsl:for&#x2D;each/tr/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[27]/table/tbody/xsl:for&#x2D;each/tr/td[2]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[27]/table/tbody/xsl:for&#x2D;each/tr/td[3]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[27]/table/tbody/xsl:for&#x2D;each/tr/td[4]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[27]/table/tbody/xsl:for&#x2D;each/tr/td[5]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[27]/table/tbody/xsl:for&#x2D;each/tr/td[6]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[27]/table/tbody/xsl:for&#x2D;each/tr/td[7]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[27]/table/tbody/xsl:for&#x2D;each/tr/td[8]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[28]/table/tbody/xsl:for&#x2D;each" x="253" y="141"/><block path="p[28]/table/tbody/xsl:for&#x2D;each/tr/td/xsl:value&#x2D;of" x="253" y="141"/><block path="p[28]/table/tbody/xsl:for&#x2D;each/tr/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[28]/table/tbody/xsl:for&#x2D;each/tr/td[2]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[28]/table/tbody/xsl:for&#x2D;each/tr/td[3]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[29]/xsl:value&#x2D;of" x="173" y="221"/><block path="p[31]/table/tbody/xsl:for&#x2D;each" x="253" y="141"/><block path="p[31]/table/tbody/xsl:for&#x2D;each/tr/td/xsl:value&#x2D;of" x="253" y="141"/><block path="p[31]/table/tbody/xsl:for&#x2D;each/tr/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[31]/table/tbody/xsl:for&#x2D;each/tr/td[2]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[31]/table/tbody/xsl:for&#x2D;each/tr/td[3]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[31]/table/tbody/xsl:for&#x2D;each/tr/td[4]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[31]/table/tbody/xsl:for&#x2D;each/tr/td[5]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[32]/xsl:value&#x2D;of" x="133" y="221"/><block path="p[33]/u/table/tbody/tr/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[33]/u/table/tbody/tr[1]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[33]/u/table/tbody/tr[2]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[33]/u/table/tbody/tr[3]/td[1]/xsl:value&#x2D;of" x="253" y="141"/><block path="p[33]/u/table/tbody/tr[4]/td[1]/xsl:value&#x2D;of" x="253" y="141"/></template></MapperBlockPosition><TemplateContext></TemplateContext><MapperFilter side="source"></MapperFilter></MapperMetaTag>
</metaInformation>
-->