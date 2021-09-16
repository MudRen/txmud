// xiuxishi.c 休息室
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","男休息室");
        set("long",@LONG
这里是男弟子的休息室，可以让他们在劳累的练功后得到疲劳缓解，
这里并排摆着几张床，看上去很舒适的样子。练了这么长时间倒下来放松
一下倒也不错。
LONG);

	set(SAFE_ENV,1);
	set("exits",([
		"south" : __DIR__"donglang1",
	]));

	set("sleep_room",1);
	setup();
	replace_program(ROOM);
}
