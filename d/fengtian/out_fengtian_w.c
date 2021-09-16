
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/fengtian/out_fengtian_w.c

inherit ROOM;

void create()
{
	set("short", "奉天府西门外");
	set("long", @LONG
走到这里就到了奉天了。东面是奉天府的西门，几个官军在
盘查着过往的行人。往西看去是一条笔直的青石官道。
LONG
	);

	set("exits", ([
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	"south" : "/d/phome/fengtian/jgz_home",
/*代码自动生成完毕.*/
 /* sizeof() == 2 */
	"east" : __DIR__"w_gate",
        "west" : "/d/path1/tch_ft21",
]));
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["east" : __DIR__"w_gate"]) );
	set( "close_look",@LONG
这里是奉天府外。西面是一条青石官道静悄悄的向远处延伸，
向东看是奉天的西门，现在天色已晚，城门已经关上了。
LONG
);
	set( "gate_name","奉天府西门" );
*/
	set("outdoors","fengtian");
	setup();
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
	create_door("south", "木门", "north", DOOR_CLOSED,LOCKED,"/d/phome/fengtian/jgz_key");
/*代码自动生成完毕.*/

}

int valid_leave(object ob,string dir)
{
	object *inv;

	if(!ob || !stringp(dir))
		return 1;

	if( userp(ob)
	&& !wizardp(ob)
	&& (dir == "east") )
	{
		inv = filter_array(deep_inventory(ob),
			(: $1->is_character()
			&& ( $1->query("attitude") == "killer"
			|| $1->query("attitude") == "aggressive" ) :));

		if(sizeof(inv))
			return notify_fail(sprintf("突然从边上跳出两个卫士说道：敢带%s进城害人，活的不耐烦啦！\n",
				inv[0]->query("name")));
	}
	return ::valid_leave(ob,dir);
}
