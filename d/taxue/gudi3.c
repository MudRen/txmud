// gudi3.c
// by dicky

inherit ROOM;
void create()
{
        set("short", "石洞");
        set("long",@long
你走进来，发现这里只是一个很小的洞穴，只能容纳七八个人。洞中光线
暗淡，什么东西都只能模糊的看个大概。靠近石壁的地方有一个石床，如果累
了，不妨在这里休息一下。
long);

	set(SAFE_ENV,1);
	set("exits",([
		"out" : __DIR__"gudi2",
	]));

	set("sleep_room",1);
        set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}
