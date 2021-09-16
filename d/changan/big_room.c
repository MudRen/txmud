// big_room  衙门大堂

inherit ROOM;
void create()
{
        set("short", "衙门大堂");
        set("long", @LONG
这里就是长安府衙的大堂，一进来你便看见上面的匾上写着
“明镜高悬”四个大字，两边的牌子上写着“肃静”、“威武”
等字样，正中是京兆尹所坐的大桌，上面摆放着惊堂木、令签以
及文房四宝，后面有一个猛虎下山的大屏风。黑漆漆的大堂，似
乎处处隐藏着什么，令你不由得腿直
发软。从里向北就出了大堂了。
LONG
        );
	set("exits", ([
                "north"            : __DIR__"yamen",
]) );

	set("objects",([
	__DIR__"npc/xianling" : 1,
]));

	setup();
	replace_program(ROOM);
}