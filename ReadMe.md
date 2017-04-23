Hi everyone,

this is a little something for CompScience Experiments i came up with during my studies at the OTH.
Some are not fully flashed out and working, others are working just fine and some are barely over the idea stage.
For the status of each subproject refer to the status.md in each folder.

Languages used are C/C++, some Java and some Lua.

===Content:===
==Conways Compression==
If you ever watched a chess game, you understand the basics of determinstic games.
Meaning a Input of Moves, by a fixed set of rules, will produce always the same output.
This compression uses the fixed Set of Rules of Conways Game of Life, to find near similar patterns, and thus compress
a given chunk of data into a List of Games and openenings.

To avoid a expensive search for the perfect game, relational operators are used on a set of games.

Algorithm::Compression:

for each Chunk of Data
for each Snapshot in the Game Archive 
	CompareSimilarity
	if highestSimilartiy
	XAND/ XOR GameState with Chunk
	Write GameOpening+NumberOfTurns+ Operator to CompressedString
	
	If CompletelyReduced -> break
END FOR
END FOR

Algorithm::DeCompression:

for each SetOfGames
	PlayGames in Reverse
	Apply to the Chunk
END FOR

Note that the Algorithm gets spead up greatly if a preexisting Number of GameSnapshots and MetaSnapshots exist. Metsnapshots are GameOfLive Games, that can be reused for example to flip one bit.

==DataPhysics==
Imagine a beach. A beach is made of particles of different sizes, aka length. Now physics apply to this beach, as a line of "processors" that grab one particle out of the array and release it to the future beach, taking the time of length of the particle. There can be emptiness between particles.

First property of this, is "entropy" that the beach is self-sorting interaction by length, as time taken to process if close to a different sized particle.

Second property is the "light-speed" of this physical simulation. This is the maximum particle length multiplied with the number of processors.

Third property is causality, causality is the range of the furthest out particle reached by the light-speed length again multiplied by the light-speed. Obviously causality can be reduced by reducing light-speed.

Fourth property is non-interaction, if you add traversable, unmoving particles into the scheduler queues, this warps "time" as in, large particles are forced to jump over them, while small particles take free particle-size time to traverse, and as being non-interacting, are invisible to the huge particles.

Sixth property is determinism. The whole physic-simulation is precise and from a deterministic input, we can derive a deterministic output, as long as causality remains unviolated.

Now for scheduling, the data-physics are rather simplistic, as the processor-front, or "time" is not repeatedly interacting with the same beach.We also can determinate ahead of time, which processor interacts with what particle, assuming light-speed is not altered. Also note, that big particle being processed equal reduced light-speed.

Now what is optimal scheduling? Optimized for throughput, as in shoving huge particles to dedicated processors, with huge fields of non-interacting particles? Fair scheduling, as in having all particles having average particle-size time going through? Prevent a causality buildup over lights-peed?

PS: I once wrote a little visualization of these data-physics, and showed them around algorithm class- nobody ever beside the prof cared for it. Nice to meet people who are fascinated by mind games.

PS^2: You can use similar property's to compress data, via Conway's game of life into deterministic lock-step simulations. Never saw that used in the wild, as you need either pre-computated simulations to be fast, or some sort of relational operator on some simple pre-set of simple simulations.

==FTree==
A FTree is a datastructure designed to model the futures.
Meaning, any branch can have subbranches and cycles.

To find out if a plan is optimal, the Following Algorithm is applied.

For each Node beginning from Present ..
	TODO outline the algo
		 the recurring escape-chances in cycles add to the chance-forrest on top of them, while at the samne time
		cycle time is substracted as a risk from the forrest overall success.
		A good plan is one, whos benefit holds true for the biggest future forrest.


==OpenInfra==
Open Infrastructure is a project, to replace traditional Internet Infrastructure with a AddHoc-Infrastructure, fashioned from Mobile Clients.

The idea is thus far the following. Every member of society, is voluntarily or not, part of commonunication cells. Example?
You rise in the morning, and your cellphone and comp, are part of the cell house/flat. You leave for work, and enter a public transportation. This is a AddHoc group, forming with some components diffrent every morning. But the busdriver is the identifying component of this group. 
His Cellphone-node overrules dissenting members of the group, interpreting this as a erly brunch.
You enter work, your cellphone is now part of the meta-organism called company, where you join a cell, called team.
If a Communicationpartner - lets call him Adam, wants to send you a Message in this network, he would throw it out to the node with the highest connection density (for example public transport) and a additional connection verifier, which would take a slower route (helping to identify sinkholes).
This density increses, as the message reaches a hub (Transitstation, airport).
By now, the message has met some organism, who knows somebody, who knows your city.
The Message of Adam follows these organisms, routed by the likelihood you would b connected to these organisms.
It reaches the busdriver, who knows you will likely join for a drive home.
You actually do this, the message arrives.
Some little later, the sink identifier reaches your home and returns with the knowledge that you got your message.

Its a rough draft, but has the potential to piss of a lot of despots.
