// tudu_seng.c

inherit NPC;

string ask_tudu(object who);
mixed ask_huansu(object me);
protected void decide_beipan(string, object);

void create()
{
	set_name("晦空", ({ "hui kong","seng" }) );
	set("title","剃度僧");

	set("class","shaolin");
	set("gender", "男性" );
	set("age", 95);
	set("long", "这是一位满脸皱纹精瘦的一位老僧人正在
蒲团上闭目打坐。\n");
	set("attitude", "peaceful");

	set("combat_exp", 200000);
	set("str", 27);
	set("max_kee",3500);
	set("kee",3500);
	set("force", 9000);
	set("max_force", 9000);
	set("force_factor", 200);

	set("inquiry",([
	"剃度" : (: ask_tudu :),
	"tidu" : (: ask_tudu :),
	"还俗" : (: ask_huansu :),
	"huansu" : (: ask_huansu :),
]));

	setup();

	carry_object(__DIR__"obj/seng_pao")->wear();
}

void init()
{
	add_action("do_kneel","kneel");
}

string ask_tudu(object who)
{
        if(who->query("marry"))
                return "少林不接受已婚配之人。\n";

	if(who->query("is_bonze"))
		return "你已是"+(who->query("class") == "shaolin"?"我寺的":"")+"出家僧人。\n";

	if(who->query("gender") != "男性")
		return "阿弥陀佛！这位女施主请到尼庵去剃度吧。\n";

	if(who->query("ever_bonze"))
		return "阿弥陀佛！少林寺不接受曾经背弃佛门之人。\n";

	who->set_temp("pending/want_tudu", 1);
	return "阿弥陀佛！施主若是真心皈依我佛，请跪下(kneel)受戒。\n";
}

int do_kneel(string arg)
{
	object who = this_player();
	string title;

	if(!who->query_temp("pending/want_tudu"))
		return 0;

	who->delete_temp("pending/want_tudu");

	if(!sscanf(who->query("title"),"少林寺第%s代弟子",title))
		who->set("title","少林寺和尚");
	who->set("is_bonze",1);
	message_vision("$N双手合十，恭恭敬敬地跪了下来。\n\n\
$n伸出手掌，在$N头顶轻轻地摩挲了几下，将$N的头发尽数剃去。\n\n", who, this_object() );
	command("say 从今以后你就是本寺的僧人了，望你洁身自好，早日修成正果。\n");
	who->save();
	return 1;
}

mixed ask_huansu(object me)
{
	if(!me->query("is_bonze"))
		return "你并没有出家为僧，还要还成怎么俗？。。。\n";

	tell_object(me, "
背叛佛门会失去所有的佛法修行，少林对于曾经背叛佛门
之人决不收留，你是否决定背叛佛门？(y/n)");

	input_to((: decide_beipan :), me);
	return 1;
}

protected void decide_beipan(string str, object me)
{
	if(!sizeof(str) || (str[0] != 'y'))
	{
		tell_object(me, "\n晦空说道：悬崖勒马，明智。\n");
		return;
	}

	me->delete("is_bonze");
	if(me->query_skill("dacheng-fofa"))
		me->delete_skill("dacheng-fofa");
	if(me->query_skill("chant"))
		me->delete_skill("chant");
	me->set("ever_bonze",1);
	if(me->query("title") == "少林寺和尚")
		me->set("title","普通百姓");
	me->save();
	tell_object(me, "\n好吧，你从今以后与佛无缘，你可以走了。\n");
}
