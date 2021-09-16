// Room: /d/path3/k_h40.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
你走在用青石铺成的官道上，不时闪躲着过往的车马和拥挤
的人群。再向南去，就是“上有天堂，下有苏杭”的杭州城了，
向北走，可以一直通到竹笠坡。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/hangzhou/out_hangzhou_n",
  "north" : __DIR__"k_h39",
]));
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
