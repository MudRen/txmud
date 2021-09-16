// Room: /u/w/wangs/b/kai115.c

inherit ROOM;

void create()
{
	set("short", "赵家宅");
	set("long", @LONG
赵家大院是一座苍松环绕的百年古屋，前后五进都是红砖砌
成的瓦屋，石阶上的青苔已被洗刷得干干净净，由大门通往前院
正房的小径也铺上了一层细沙，两侧野草全部铲平，连沿路的树
枝也都剪修得整整齐齐，一看就知道主人下了很大的功夫。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"kai113",
  "east" : __DIR__"kai114",
]));
        set("objects",([
        __DIR__"npc/yongren":1,
]));

	setup();
	replace_program(ROOM);
}
