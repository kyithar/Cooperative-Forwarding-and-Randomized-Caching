package networks;

network abilene_network extends base_network{

    parameters:
        //Number of ccn nodes
    	n = 25;

connections allowunconnected:
    node[2].face++ <--> { delay = 5.48ms; } <--> node[0].face++;
	node[2].face++ <--> { delay = 5.48ms; } <--> node[1].face++;
	node[3].face++ <--> { delay = 3.80ms; } <--> node[2].face++;
	node[4].face++ <--> { delay = 3.80ms; } <--> node[2].face++;
	node[4].face++ <--> { delay = 3.80ms; } <--> node[3].face++;
	node[5].face++ <--> { delay = 3.80ms; } <--> node[2].face++;
	node[5].face++ <--> { delay = 3.80ms; } <--> node[4].face++;
	node[5].face++ <--> { delay = 3.80ms; } <--> node[3].face++;
	node[6].face++ <--> { delay = 3.80ms; } <--> node[2].face++;		
	node[6].face++ <--> { delay = 3.80ms; } <--> node[3].face++;
	node[6].face++ <--> { delay = 3.80ms; } <--> node[4].face++;
	node[6].face++ <--> { delay = 3.80ms; } <--> node[5].face++;
	node[7].face++ <--> { delay = 3.80ms; } <--> node[3].face++;
	node[8].face++ <--> { delay = 3.80ms; } <--> node[3].face++;
	node[9].face++ <--> { delay = 3.80ms; } <--> node[4].face++;
	node[10].face++ <--> { delay = 3.80ms; } <--> node[4].face++;
	node[11].face++ <--> { delay = 3.80ms; } <--> node[5].face++;
	node[12].face++ <--> { delay = 3.80ms; } <--> node[5].face++;
	node[14].face++ <--> { delay = 3.80ms; } <--> node[6].face++;
	node[14].face++ <--> { delay = 3.80ms; } <--> node[13].face++;
	node[15].face++ <--> { delay = 3.80ms; } <--> node[13].face++;
	node[15].face++ <--> { delay = 3.80ms; } <--> node[14].face++;
	node[16].face++ <--> { delay = 3.80ms; } <--> node[13].face++;
	node[16].face++ <--> { delay = 3.80ms; } <--> node[14].face++;
	node[16].face++ <--> { delay = 3.80ms; } <--> node[15].face++;
	node[17].face++ <--> { delay = 3.80ms; } <--> node[13].face++;
	node[18].face++ <--> { delay = 3.80ms; } <--> node[13].face++;
	node[19].face++ <--> { delay = 3.80ms; } <--> node[14].face++;
	node[20].face++ <--> { delay = 3.80ms; } <--> node[14].face++;
	node[21].face++ <--> { delay = 3.80ms; } <--> node[15].face++;
	node[22].face++ <--> { delay = 3.80ms; } <--> node[15].face++;
	node[23].face++ <--> { delay = 3.80ms; } <--> node[16].face++;
	node[24].face++ <--> { delay = 3.80ms; } <--> node[16].face++;

}