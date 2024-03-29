// Room: /d/shaolin/baodian.c

inherit ROOM;

void create()
{
	set("short", "大雄宝殿");
	set("long", @LONG
这里是少林寺的大雄宝殿，一进门好不庄严，一尊数丈高的
释迦牟尼圣像在正中，左右是阿傩、迦叶二胁侍。大殿东西两廊
供奉着十六罗汉，神态各异。由于大殿很高，前面供桌上放置着
各种法器，加上香火的烟霭霭飘荡，使你感觉人类的渺小和佛法
的无边力量，竟不同自主地想跪在前面的蒲团上。从这里向西是
左配殿，向东是右配殿，绕过佛像向北是一条青古甬道，南边下
了石阶便是中院广场了。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "northdown" : __DIR__"yongdao1",
  "southdown" : __DIR__"m_square",
  "east" : __DIR__"e_pei",
  "west" : __DIR__"w_pei",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
