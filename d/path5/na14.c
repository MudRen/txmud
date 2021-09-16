// Room: /d/path5/na14.c

inherit ROOM;

void create()
{
	set("short", "窑洞内室");
	set("long", @LONG
这是窑洞的内室，洞角有一张用木板和茅草搭成的床。床上
躺着李老汉的女儿红霞。自从小时候发过一场高烧后，就得了一
种怪病，一直昏迷不醒，卧床不起。李老汉给她请了一些朗中，
但未能凑效。
LONG
	);
/*
	set("item_desc",([
          "床":"这是一张用木板和茅草搭成的床。床上
躺着李老汉的女儿红霞。\n",
          "红霞":"这就是李老汉的女儿红霞。肌黄的脸上隐露
着一丝黑气，看起来命不久矣。 \n",
]));
*/
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"na13",
]));
	setup();
	replace_program(ROOM);
}
