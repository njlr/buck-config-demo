# buck-config-demo

## Project Structure

 * Library `foo` in it's own cell at `./vendor/foo`
 * Application `app` at the top-level
 * Both components use a preprocessor variable `FOO` so that we can see how configurations get applied.
 * Buck allows us to supply different configurations to each component!

## Instructions

To do a regular build:

```bash=
$ buck run :app
foo says: DEFAULTFOO
app says: DEFAULTFOO
```

To do a release build using CLI arguments:

```bash=
$ buck run :app -c *//cxx.cxxppflags='-DFOO=RELEASEFOO'
Building: finished in 0.6 sec (100%) 3/3 jobs, 1 updated
  Total time: 1.0 sec
foo says: RELEASEFOO
app says: RELEASEFOO
```

To do a release build using arg-files (more convenient):

```bash=
$ buck run @config/release :app
Building: finished in 1.3 sec (100%) 8/8 jobs, 4 updated
  Total time: 1.6 sec
foo says: RELEASEFOOUSINGCONFIG
app says: RELEASEFOOUSINGCONFIG
```

You can also override the settings found in an arg-file. This is very powerful!

```bash=
$ buck run @config/release -c foo//cxx.cxxppflags='-DFOO=CUSTOMFOO' :app
Building: finished in 1.1 sec (100%) 7/7 jobs, 3 updated
  Total time: 1.4 sec
foo says: CUSTOMFOO
app says: RELEASEFOOUSINGCONFIG
```

More information can be found [in the docs](https://buckbuild.com/command/common_parameters.html). 
