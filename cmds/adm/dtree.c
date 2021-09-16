// dtree.c

inherit F_CLEAN_UP;

nomask int main(object me, string arg)
{
	string path,*files;
	int count;

	if(!arg || (arg == ""))
		return notify_fail("无参数错误。\n");

	path = resolve_path(me->query("cwd"), arg);

	if(file_size(path) != -2)
		return notify_fail(path+" 不是一个目录。\n");

	path += "/";
	files = get_dir(path);

	foreach(string file in files)
	{
		object ob = find_object(sprintf("%s%s",path,file));
		if(objectp(ob))
		{
			count++;
			destruct(ob);
		}
	}

	printf("共清除 %d 个物件。\n",count);
	return 1;
}
