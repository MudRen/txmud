// Room: /wiz/find/huapu/pu.c
// 可采金银花。

inherit ROOM;

void create()
{
	set("short", "百花圃");
	set("long", @LONG
这是一处巨大的花圃，花圃里四季都开放这个色的鲜花，据
说这个花圃只有掌门的贴身仆人逾二嫂才能维护。绯雨阁的掌门
也经常来到这里赏花散心。
LONG
	);

	set("outdoors","feiyu");

	setup();
}
