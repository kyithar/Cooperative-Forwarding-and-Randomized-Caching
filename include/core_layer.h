/*
 * ccnSim is a scalable chunk-level simulator for Content Centric
 * Networks (CCN), that we developed in the context of ANR Connect
 * (http://www.anr-connect.org/)
 *
 * People:
 *    Giuseppe Rossini (lead developer, mailto giuseppe.rossini@enst.fr)
 *    Raffaele Chiocchetti (developer, mailto raffaele.chiocchetti@gmail.com)
 *    Dario Rossi (occasional debugger, mailto dario.rossi@enst.fr)
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 * 
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef CCN_NODE_H
#define CCN_NODE_H

#include <omnetpp.h>
#include "ccnsim.h"

#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>

using namespace std;
using namespace boost;

class ccn_interest;
class ccn_data;

class strategy_layer;
class base_cache;


//This structure takes care of data forwarding
struct pit_entry {
    interface_t interfaces;
    unordered_set<int> nonces;
    simtime_t time; //<aa> last time this entry has been updated</aa>
    int custo_marking;// to know custodian router or not(0 = not custodian, 1= custodian)
    int custo_int;
    //int CB;//cache bit
//pit_entry():CB(0){;}
};
struct cstat_entry {
int cache_miss;
int custodian_hit;
double access_freq;
double req_count;
double uni_dis;
int CB;
double cache_cost;
double nu;
double p;
double B;
double test;
double cu;
double q;
cstat_entry ():req_count(0),uni_dis(-1), CB(0), cache_cost(-1), nu(0), p(0), B(-1), test(0), cu(0), q(0){;}
};

struct reset_entry {

double req_count;
reset_entry ():req_count(0){;}
};

class core_layer : public abstract_node{
    friend class statistics;
    
    public:
    	void check_if_correct(int line);
		//<aa>
		#ifdef SEVERE_DEBUG
		bool it_has_a_repo_attached;

		vector<int> get_interfaces_in_PIT(chunk_t chunk);
		bool is_it_initialized;
		#endif

		double get_repo_price();
		//void set_repo_price(double price);
		//</aa>

    protected:
		//Standard node Omnet++ functions
		virtual void initialize();
		virtual void handleMessage(cMessage *);
		virtual void finish();

		//<aa> See ned file
		bool interest_aggregation;
		bool transparent_to_hops;
		double repo_price; //the price of the attached repository.
		void add_to_pit(chunk_t chunk, int gate);
		//</aa>

		//Custom functions
		void handle_interest(ccn_interest *);
		void handle_cdecision(ccn_interest *);
		void handle_ghost(ccn_interest *);
		void handle_data(ccn_data *);
		void handle_decision(bool *, ccn_interest *);

		void cdecision_cal(ccn_data *);


		bool check_ownership(vector<int>);
		ccn_data *compose_data(uint64_t);	
		void clear_stat();

		virtual void handle_timers(cMessage*);

    private:
		cMessage *timer;
		unsigned long max_pit;
		unsigned short nodes;
		unsigned int my_bitmask;
		double my_btw;
		double RTT;
		static int repo_interest; 	// <aa> total number of interests set to one of the
									// repositories of the network </aa>
		int current_r;//current router
		int cluster_id;
		int client_attached;
		double weight;

		//<aa> number of chunks satisfied by the repository attached to this node</aa>
		int repo_load; 
		double normal_mean;
		double test_cost;
		int start_alg;

		double x;
		double u;
		double v;
		double B;
		double counter,arrival,w;

		simtime_t check_time;
	

		//Architecture data structures
		boost::unordered_map <chunk_t, pit_entry > PIT;
		boost::unordered_map <chunk_t, cstat_entry > Cstat;
		boost::unordered_map <chunk_t, reset_entry > Reset;
		boost::unordered_map<int,int>  CHring;
		base_cache *ContentStore;
		base_cache *RContentStore;
		strategy_layer *strategy;

		//Statistics
		int interests;
		int data;
		int unwanted_data;

		//<aa>
		#ifdef SEVERE_DEBUG
		int unsolicited_data;	// Data received by the node but not requested by anyone

		int discarded_interests; //number of incoming interests discarded
								 // because their TTL is > max hops
		int unsatisfied_interests;	//number of interests for contents that are neither
									//in the cache nor in the repository of this node	
		int interests_satisfied_by_cache;

		#endif
		int	send_data (ccn_data* msg, const char *gatename, int gateindex, int line_of_the_call);
		//</aa>
};
#endif

