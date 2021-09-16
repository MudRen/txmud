// Room: /u/w/wangs/b/kai142.c

inherit ROOM;

void create()
{
	set("short", "天马镖局");
	set("long", @LONG
一座建构宏伟的宅第，左右两座石坛中各竖一根两丈来高的
旗杆，杆顶飘扬青旗。右首旗上黄色丝线绣着一头张牙舞爪，神
态威猛的雄狮，旗子随风招展，显得雄狮更奕奕若生。雄狮头顶
有一对黑丝线绣的蝙蝠展翅飞翔。左首旗上绣着“天马镖局”四
个黑字，银钩铁划，刚劲非凡。大宅朱漆大门，门上茶杯大小的
铜钉闪闪发光，门顶匾额写着“天马镖局”四个金漆大字，下面
横书“总号”两个小字。　
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kai149",
  "south" : __DIR__"kai141",
]));
        set("objects",([
        __DIR__"npc/hb": 1,
]));

	setup();
	replace_program(ROOM);
}
