# deploy-test

A tiny one-page site, built just to practice pushing something to GitHub and getting it live on the web. No frameworks, no build step — just `index.html`.

## What it does

Shows a fake terminal log of a deploy (`git push` → `build` → `live`) with a live clock. If you can see the clock ticking, your deployment worked.

## Deploy it yourself (GitHub Pages, free, no server needed)

1. **Create a repo**
   - Go to [github.com/new](https://github.com/new), name it something like `deploy-test`, keep it public, create it.

2. **Push this folder to it**
   ```bash
   cd test-site
   git init
   git add .
   git commit -m "first deploy test"
   git branch -M main
   git remote add origin https://github.com/<your-username>/deploy-test.git
   git push -u origin main
   ```

3. **Turn on Pages**
   - In the repo, go to **Settings → Pages**.
   - Under "Build and deployment", set **Source** to `Deploy from a branch`.
   - Pick branch `main`, folder `/ (root)`, then **Save**.

4. **Wait ~1 minute, then visit**
   ```
   https://<your-username>.github.io/deploy-test/
   ```

That's it — every time you push a change to `main`, Pages rebuilds automatically. Good next steps once this feels routine: try a GitHub Actions workflow that deploys on push (you already know the shape of this from CI/CD), then point the same idea at Vercel or Render for your bigger projects like ZyroFit.
